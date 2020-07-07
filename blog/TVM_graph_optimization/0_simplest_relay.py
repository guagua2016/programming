from tvm import relay
import tvm.relay.op


x = relay.expr.var('x', relay.scalar_type('int64'), dtype = 'int64')
one = relay.expr.const(1, dtype = 'int64')
add = relay.op.tensor.add(x, one)    
func = relay.Function([x], add, relay.scalar_type('int64'))

print(type(func))

mod = tvm.ir.IRModule.from_expr(func)  #

# print(dir(mod))
# print(type(mod.functions.items()[0][1]))
# print(dir(mod.functions.items()[0][1]))
# print(mod.functions.items()[0][1].attrs)
# print(mod.functions.items()[0][1].body)
# print(mod.functions.items()[0][1].ret_type)
# print(mod.functions.items()[0][1].span)
# print(mod.functions.items()[0][1].type_params)

# print("Relay module function:\n", mod.astext(show_meta_data=False))

# graph, lib, params = tvm.relay.build(mod, 'llvm', params={})
# print("TVM graph:\n", graph)
# print("TVM parameters:\n", params)
# print("TVM compiled target function:\n", lib.get_source())


# [  
#     (
#         GlobalVar(main), 
#         FunctionNode
#             (
#                 [Var(x, ty=TensorType([], int64))], 
#                 TensorType([], int64), 
#                 CallNode(Op(add), [Var(x, ty=TensorType([], int64)), Constant(1)], (nullptr), [TensorType([], int64), TensorType([], int64)]), 
#                 [], 
#                 (nullptr)
#             )
#     )
# ]
