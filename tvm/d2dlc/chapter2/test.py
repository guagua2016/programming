

# import numpy as np



# a = np.random.normal(size=(3,4)).astype('float32')

# print(a,type(a))


# print(a.sum(axis=1))


# import numpy as np
# import timeit

# x = None
# def benchmark(dtype):
#     x = np.random.normal(size=(1000, 1000)).astype(dtype)
#     import time
#     start = time.time()
#     np.dot(x,x)
#     print(time.time()-start)
# benchmark('float32')
# benchmark('float64')
# benchmark('int32')
# benchmark('int64')
# benchmark('int8')

import timeit
import numpy as np
from matplotlib import pyplot as plt
from IPython import display

timer = timeit.Timer(setup='import numpy as np',
                     stmt='np.zeros((4, 4))')


print(timer.timeit(100))


# Save to the d2ltvm package.
def bench_workload(workload):
    """Benchmarka a workload

    workload - must accept a num_repeat argument and return the total runtime
    """
    workload(1)  # warmup
    time = workload(1)  # the time to run once
    if time > 1: return time
    # The number of repeats to measure at least 1 second.
    num_repeats = max(int(1.0 / time), 5)
    return workload(num_repeats) / num_repeats

print('time for np.zeros((4, 4)):', bench_workload(timer.timeit))


def np_setup(n):
    return 'import numpy as np\n' \
           'x = np.random.normal(size=%d).astype("float32")\n' \
           'y = np.empty_like(x)\n'% n

def np_copy(n):
    return timeit.Timer(setup=np_setup(n),
                        stmt='np.copyto(y, x)')

sizes = 2**np.arange(5, 20, 4).astype('int')
print(sizes)
np_times = [bench_workload(np_copy(n).timeit) for n in sizes]
print(np_times)

display.set_matplotlib_formats('svg')

plt.loglog(sizes, sizes*4/np_times/1e9)
plt.xlabel('Vector length')
plt.ylabel('Throughput (GB/sec)')
plt.grid()



sizes = 2**np.arange(1, 8).astype('int')
np_times = np.array([bench_workload(np_copy(n).timeit) for n in sizes])

print('NumPy call overhead: %.1f microsecond' % (np_times.mean()*1e6))


def tvm_copy(n):
    return timeit.Timer(setup=np_setup(n)+'import tvm\n'
                        'x, y = tvm.nd.array(x), tvm.nd.array(y)',
                        stmt='x.copyto(y)')

tvm_times = np.array([bench_workload(tvm_copy(n).timeit) for n in sizes])
print('TVM call overhead: %.1f microsecond'% (tvm_times.mean()*1e6,))