# https://rufflewind.com/2016-12-30/reverse-mode-automatic-differentiation

import tvm
import topi
import numpy

x = tvm.te.placeholder((3,), name='x')
w = tvm.te.placeholder((3,),name='w')
z1 = topi.multiply(x,w)
z2 = topi.sum(z1)
z3 = topi.multiply(z2,-1)
z4 = topi.exp(z3)
z5 = topi.add(z4,1)
z6 = topi.divide(1,z5)

[dw] = tvm.te.gradient(z6,w)
print(type(dw.op))
s2 = tvm.te.create_schedule(dw.op)
print(type(s2))
g = tvm.build(s2,[x,w,dw])


# The default tensor type in tvm
dtype = "float32"

# using Intel AVX2(Advanced Vector Extensions) ISA for SIMD
# To get the best performance, please change the following line
# to llvm -mcpu=core-avx2, or specific type of CPU you use
target = 'llvm'
ctx = tvm.context(target, 0)

# # Random generated tensor for testing
x1 = tvm.nd.array(numpy.array([1,3,2]).astype(dtype), ctx)
w1 = tvm.nd.array(numpy.array([2,1,-2]).astype(dtype), ctx)
dw1 = tvm.nd.empty(shape=(3,),dtype='float32',ctx=ctx)
g(x1,w1,dw1)
print(dw1)