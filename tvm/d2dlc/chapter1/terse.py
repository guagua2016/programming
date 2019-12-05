# from tvm._ffi import base

# import tvm
# import tvm._ffi.base as b

# import tvm._ffi.function as f

# print(f.list_global_func_names())

import tvm.make as m


x = m.node("IntImm", dtype="int32", value=10)

print(x)


# # import tvm._ffi.function


# class Test(object):
#     """docstring for Test"""
#     # def __init__(self, arg):
#     #     super(Test, self).__init__()
#     #     self.arg = arg

#     def __hash__(self):
#         print("hello")
        

# # myadd = tvm.get_global_func("myadd")

# a = Test()
# print(type(a))
# a.__hash__()


# t = tvm.tensor.Tensor()
# t.__hash__()
# print(type(t))

# # print(tvm._ffi.function.list_global_func_names())

# # prints 3
# # print(myadd(1, 2))