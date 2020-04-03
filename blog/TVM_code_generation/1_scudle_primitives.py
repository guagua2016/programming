import tvm
import numpy
import timeit

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
answer = numpy.dot(a.asnumpy(), b.asnumpy())

# Algorithm
k = tvm.reduce_axis((0, K), 'k')
A = tvm.placeholder((M, K), name='A')
B = tvm.placeholder((K, N), name='B')

bn = 32


print("==== Adjust memory out === ")
packedB = tvm.compute((N / bn, K, bn), lambda x, y, z: B[y, x * bn + z], name='packedB')
C = tvm.compute((M, N),
                lambda x, y: tvm.sum(A[x, k] * packedB[y // bn, k, tvm.indexmod(y, bn)], axis=k),
                name = 'C')

s = tvm.create_schedule(C.op)
print("========================== origin ======================= ")
print(tvm.lower(s, [A, B, C], simple_mode=True))


CC = s.cache_write(C, 'global')
print("========================== cache c ======================= ")
print(tvm.lower(s, [A, B, C], simple_mode=True))



xo, yo, xi, yi = s[C].tile(C.op.axis[0], C.op.axis[1], bn, bn)
print("========================== title 32 * 32 ================= ")
print(tvm.lower(s, [A, B, C], simple_mode=True))


s[CC].compute_at(s[C], yo)
print("========================== compute at ================= ")
print(tvm.lower(s, [A, B, C], simple_mode=True))


xc, yc = s[CC].op.axis
k, = s[CC].op.reduce_axis
ko, ki = s[CC].split(k, factor=4)
print("========================== split * 4 ================== ")
print(tvm.lower(s, [A, B, C], simple_mode=True))

s[CC].reorder(ko, xc, ki, yc)
print("========================== reorder ================== ")
print(tvm.lower(s, [A, B, C], simple_mode=True))


s[CC].unroll(ki)  # 循环展开
print(tvm.lower(s, [A, B, C], simple_mode=True))
s[CC].vectorize(yc)
s[C].parallel(xo)
print("========================== unroll vectorize parallel ================== ")
print(tvm.lower(s, [A, B, C], simple_mode=True))


x, y, z = s[packedB].op.axis
s[packedB].vectorize(z)
s[packedB].parallel(x)

print("========================== adjust packedB ================== ")
print(tvm.lower(s, [A, B, C], simple_mode=True))

func = tvm.build(s, [A, B, C], target=target, name = 'mmult')
assert func

c = tvm.nd.array(numpy.zeros((M, N), dtype = dtype), ctx)
func(a, b, c)
tvm.testing.assert_allclose(c.asnumpy(), answer, rtol=1e-5)

evaluator = func.time_evaluator(func.entry_name, ctx, number=50)
opt6_time = evaluator(a, b, c).mean
print('Opt6: %f' % opt6_time)