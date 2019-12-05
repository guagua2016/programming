import inspect
from IPython import display
import numpy as np
from matplotlib import pyplot as plt
import timeit
import tvm


from d2ltvm import d2ltvm


sizes = 2**np.arange(5, 29, 4)
np_add = lambda n: timeit.Timer(setup='import numpy as np\n'
                                'from d2ltvm import d2ltvm\n'
                                'a, b, c = d2ltvm.get_abc(%d)' % n,
                                stmt='np.add(a, b, out=c)')
np_times = [d2ltvm.bench_workload(np_add(n).timeit) for n in sizes]

np_gflops = 2 * sizes / 1e9 /np.array(np_times)

print(np_times)
print(np_gflops)

# d2ltvm.plot_gflops(sizes, [np_gflops], ['numpy'])



def default(n):
    A, B, C = d2ltvm.vector_add(n)
    s = tvm.create_schedule(C.op)
    return s, (A, B, C)

s, args = default(64)
print(tvm.lower(s, args, simple_mode=True))




# target = 'llvm -mcpu=core-avx2'
target = 'llvm -mcpu=core-avx2'
mod = tvm.build(s, args, target)
print(mod.get_source()[:500])

default_gflops = d2ltvm.bench_vector_add_tvm(default, sizes, target)
# d2ltvm.plot_gflops(sizes, [np_gflops, default_gflops], ['numpy', 'default'])


# print("default", default_gflops)
# import os
# os._exit(-1)












def parallel(n):
    s, (A, B, C) = default(n)
    s[C].parallel(C.op.axis[0])
    return s, (A, B, C)

s, args = parallel(64)
print(tvm.lower(s, args, simple_mode=True))

parallel_gflops = d2ltvm.bench_vector_add_tvm(parallel, sizes, target)
# d2ltvm.plot_gflops(sizes, [np_gflops, default_gflops, parallel_gflops],
#      ['numpy', 'default', 'parallel'])



def vectorized(n):
    s, (A, B, C) = default(n)
    outer, inner = s[C].split(C.op.axis[0], factor=8)
    s[C].parallel(outer)
    s[C].vectorize(inner)
    return s, (A, B, C)

s, args = vectorized(64)
print(tvm.lower(s, args, simple_mode=True))
vectorized_gflops = d2ltvm.bench_vector_add_tvm(vectorized, sizes, target)
d2ltvm.plot_gflops(sizes, [np_gflops, default_gflops, parallel_gflops, vectorized_gflops],
     ['numpy', 'default', 'parallel', 'vectorized'])