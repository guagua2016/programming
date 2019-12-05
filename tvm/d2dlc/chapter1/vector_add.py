import tvm
import numpy as np

# Save to the d2ltvm package.
def get_abc(shape, constructor=None):
    """Return random a, b and empty c with the same shape.
    """
    np.random.seed(0)
    a = np.random.normal(size=shape).astype(np.float32)
    b = np.random.normal(size=shape).astype(np.float32)
    c = np.empty_like(a)
    if constructor is not None:
        a, b, c = [constructor(x) for x in (a, b, c)]
    return a, b, c


# Save to the d2ltvm package.
# computtation
def vector_add(n):
    """TVM expression for vector addition"""
    A = tvm.placeholder((n,), name='a')
    B = tvm.placeholder((n,), name='b')
    C = tvm.compute(A.shape, lambda i: A[i] + B[i], name='c')
    return A, B, C

A, B, C = vector_add(n=200)
print(type(A), type(C))
print(type(A.op), type(C.op))


# schedule
s = tvm.create_schedule(C.op)
print(s, type(s[C]))


# pseudo code
print(tvm.lower(s, [A,B,C],simple_mode=True))


# compile
mod = tvm.build(s,[A,B,C])
print(type(mod))
mod_fname = "vector-add.tar"
mod.export_library(mod_fname)


try:
    a, b, c = get_abc(200, tvm.nd.array)
    mod(a, b, c)
except tvm.TVMError as e:
    print(e)