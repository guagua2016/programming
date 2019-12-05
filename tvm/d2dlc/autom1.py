import tvm
import numpy
import timeit
from tvm import autotvm
import logging
import sys
# The size of the matrix
# (M, K) x (K, N)
# You are free to try out different shapes, sometimes TVM optimization outperforms numpy with MKL.
M = 1024
K = 1024
N = 1024

# The default tensor type in tvm
dtype = "float32"

# using Intel AVX2(Advanced Vector Extensions) ISA for SIMD
# To get the best performance, please change the following line
# to llvm -mcpu=core-avx2, or specific type of CPU you use
target = 'llvm -mcpu=core-avx2'
ctx = tvm.context(target, 0)

# Random generated tensor for testing
a = tvm.nd.array(numpy.random.rand(M, K).astype(dtype), ctx)
b = tvm.nd.array(numpy.random.rand(K, N).astype(dtype), ctx)

np_repeat = 100
np_runing_time = timeit.timeit(setup='import numpy\n'
                                     'M = ' + str(M) + '\n'
                                     'K = ' + str(K) + '\n'
                                     'N = ' + str(N) + '\n'
                                     'dtype = "float32"\n'
                                     'a = numpy.random.rand(M, K).astype(dtype)\n'
                                     'b = numpy.random.rand(K, N).astype(dtype)\n',
                               stmt='answer = numpy.dot(a, b)',
                               number=np_repeat)
print("Numpy running time: %f" % (np_runing_time / np_repeat))

answer = numpy.dot(a.asnumpy(), b.asnumpy())

@autotvm.template
def matmul():
    # Algorithm
    k = tvm.reduce_axis((0, K), 'k')
    A = tvm.placeholder((M, K), name='A')
    B = tvm.placeholder((K, N), name='B')

    ##### define space begin #####
    cfg = autotvm.get_config()
    cfg.define_split("tile_x", M, num_outputs=2)
    cfg.define_split("tile_y", N, num_outputs=2)
    cfg.define_split("tile_k", K, num_outputs=2)
    ##### define space end #####

    # We have to re-write the algorithm slightly.
    bn = cfg["tile_y"].size[-1]
    packedB = tvm.compute((N / bn, K, bn), lambda x, y, z: B[y, x * bn + z], name='packedB')
    C = tvm.compute((M, N),
                    lambda x, y: tvm.sum(A[x, k] * packedB[tvm.div(y,bn), k, y % bn], axis=k),
                    name = 'C')
    s = tvm.create_schedule(C.op)
    x, y = s[C].op.axis
    k, = s[C].op.reduce_axis

    # schedule according to config
    # Allocate write cache
    CC = s.cache_write(C, 'global')
    xo, xi = cfg["tile_x"].apply(s, C, x)
    yo, yi = cfg["tile_y"].apply(s, C, y)
    s[C].reorder(xo, yo, xi, yi)

    # Write cache is computed at yo
    s[CC].compute_at(s[C], yo)

    # New inner axes
    xc, yc = s[CC].op.axis

    k, = s[CC].op.reduce_axis
    ko, ki = cfg["tile_k"].apply(s, CC, k)
    s[CC].reorder(ko, xc, ki, yc)
    s[CC].unroll(ki)
    s[CC].vectorize(yc)
    # parallel
    s[C].parallel(xo)

    x, y, z = s[packedB].op.axis
    s[packedB].vectorize(z)
    s[packedB].parallel(x)

    return s, [A, B, C]

task = autotvm.task.create(matmul, args=[], target=target)

measure_option = autotvm.measure_option(
    builder='local',
    runner=autotvm.LocalRunner(number=5))

# begin tuning, log records to file `matmul.log`
tuner = autotvm.tuner.XGBTuner(task)
n_trial = 2000
early_stopping = 800
tuner.tune(n_trial=n_trial,
           early_stopping=early_stopping,
           measure_option=measure_option,
           callbacks=[autotvm.callback.progress_bar(n_trial),
                      autotvm.callback.log_to_file('matmul.log.tmp')])
# pick best records to a cache file
autotvm.record.pick_best("matmul.log.tmp", 'matmul.log')

with autotvm.apply_history_best('matmul.log'):
    with tvm.target.create("llvm -mcpu=core-avx2"):
        s, arg_buf = matmul()
        func = tvm.build(s, arg_buf)
# func = tvm.build(s, arg_buf, target=target, name='mmult')
assert func

c = tvm.nd.array(numpy.zeros((M, N), dtype=dtype), ctx)


func(a, b, c)
tvm.testing.assert_allclose(c.asnumpy(), answer, rtol=1e-5)
# print(func.get_source("asm"))

evaluator = func.time_evaluator(func.entry_name, ctx, number=100)
print('TVM: %f' % evaluator(a, b, c).mean)