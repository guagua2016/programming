
import d2ltvm
import numpy as np
import tvm



sizes = 2**np.arange(5, 12, 1)
np_times = [d2ltvm.bench_workload(d2ltvm.np_matmul_timer(n)) for n in sizes]
np_gflops = 2 * sizes **3 / 1e9 / np.array(np_times)


print(np_gflops)



def default(n):
    A, B, C = d2ltvm.matmul(n, n, n)
    return tvm.create_schedule(C.op), (A, B, C)

s, args = default(64)
print(tvm.lower(s, args, simple_mode=True))

target = 'llvm -mcpu=core-avx2'
default_gflops = d2ltvm.bench_matmul_tvm(default, sizes, target)
# d2ltvm.plot_gflops(sizes, [np_gflops, default_gflops], ['numpy', 'default'])


def reorder(n):
    s, (A, B, C) = default(n)
    (x, y), (k,) = C.op.axis, C.op.reduce_axis
    s[C].reorder(x, k, y)
    return s, (A, B, C)

s, args = reorder(64)
print(tvm.lower(s, args, simple_mode=True))
reorder_gflops = d2ltvm.bench_matmul_tvm(reorder, sizes, target)

def parallel(n):
    s, (A, B, C) = reorder(n)
    s[C].parallel(C.op.axis[0])
    return s, (A, B, C)

s, args = parallel(64)
print(tvm.lower(s, args, simple_mode=True))

parallel_gflops = d2ltvm.bench_matmul_tvm(parallel, sizes, target)
d2ltvm.plot_gflops(sizes, [np_gflops, default_gflops, reorder_gflops, parallel_gflops],
            ['numpy', 'default', 'reorder', 'parallel'])