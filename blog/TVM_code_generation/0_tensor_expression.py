import tvm
import numpy
import timeit

K = 1024
M = 1024
N = 1024

# The default tensor type in tvm
dtype = "float32"

# step1. Describe the Computation
k = tvm.reduce_axis((0, K), 'k')
A = tvm.placeholder((M, K), name='A')
B = tvm.placeholder((K, N), name='B')
C = tvm.compute(
           (M, N),
           lambda x, y: tvm.sum(A[x, k] * B[k, y], axis=k),
           name='C')


# step2. Schedule the Computation
s = tvm.create_schedule(C.op)
print(tvm.lower(s, [A, B, C], simple_mode=True))
bn = 16
xo, yo, xi, yi = s[C].tile(C.op.axis[0], C.op.axis[1], bn, bn) 
print("======= tile 16*16 ======= ")
print(tvm.lower(s, [A, B, C], simple_mode=True))
k, = s[C].op.reduce_axis
print("======== split k 4 ====== ",type(k))
ko, ki = s[C].split(k, factor=4)
print(tvm.lower(s, [A, B, C], simple_mode=True))


# step3. Compilation
target = 'llvm -mcpu=core-avx2'
ctx = tvm.context(target, 0)
func = tvm.build(s, [A, B, C], target=target, name='mmult')
assert func


# step4. Run the Function
# Random generated tensor for testing
a = tvm.nd.array(numpy.random.rand(M, K).astype(dtype), ctx)
b = tvm.nd.array(numpy.random.rand(K, N).astype(dtype), ctx)
c = tvm.nd.array(numpy.zeros((M, N), dtype = dtype), ctx)
answer = numpy.dot(a.asnumpy(), b.asnumpy())
func(a, b, c)
tvm.testing.assert_allclose(c.asnumpy(), answer, rtol=1e-5)
evaluator = func.time_evaluator(func.entry_name, ctx, number=10)
print('Opt2: %f' % evaluator(a, b, c).mean)