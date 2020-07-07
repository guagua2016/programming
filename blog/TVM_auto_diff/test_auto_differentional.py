import tvm
import topi

x = tvm.te.placeholder((32, 3, 28, 28), name='x')
w1 = tvm.te.placeholder((10, 3, 3, 3), name='w1')
w2 = tvm.te.placeholder((10, 10, 3, 3), name='w2')
z1 = topi.nn.conv2d(x, w1, 1, 1, 1)
z2 = topi.nn.conv2d(z1, w2, 1, 1, 1)
y = topi.sum(z2)

# produce gradients
[dw1] = tvm.te.gradient(y, [w1])

print(type(dw1))

# produce Jacobians
[jw1, jw2] = tvm.te.gradient(z2, [w1, w2])

# produce gradients, the head adjoint for z2 is provided manually
[dw1, dw2] = tvm.te.gradient(z2, [w1, w2], topi.full_like(z2, 1.0))