
from tvm import relay
import tvm
from tvm.relay import transform
import tvm.relay as relay
import numpy as np
# import runtime 
# from .init import create_workload

from tvm.contrib import graph_runtime

def batch_norm_infer(data,
                     gamma=None,
                     beta=None,
                     moving_mean=None,
                     moving_var=None,
                     **kwargs):
    name = kwargs.get("name")
    kwargs.pop("name")
    if not gamma:
        gamma = relay.var(name + "_gamma")
    if not beta:
        beta = relay.var(name + "_beta")
    if not moving_mean:
        moving_mean = relay.var(name + "_moving_mean")
    if not moving_var:
        moving_var = relay.var(name + "_moving_var")
    return relay.nn.batch_norm(data,
                               gamma=gamma,
                               beta=beta,
                               moving_mean=moving_mean,
                               moving_var=moving_var,
                               **kwargs)[0]


def conv2d(data, weight=None, **kwargs):
    name = kwargs.get("name")
    kwargs.pop("name")
    if not weight:
        weight = relay.var(name + "_weight")
    return relay.nn.conv2d(data, weight, **kwargs)


def conv_block(data, name, channels, kernel_size=(3, 3), strides=(1, 1),
               padding=(1, 1), epsilon=1e-5):
    conv = conv2d(
        data=data,
        channels=channels,
        kernel_size=kernel_size,
        strides=strides,
        padding=padding,
        data_layout='NCHW',
        name=name+'_conv')
    bn = batch_norm_infer(data=conv, epsilon=epsilon, name=name + '_bn')
    act = relay.nn.relu(data=bn)
    return act



data_shape = (1, 3, 224, 224)
kernel_shape = (32, 3, 3, 3)
dtype = "float32"
data = relay.var("data", shape=data_shape, dtype=dtype)
act = conv_block(data, "graph", 32, strides=(2, 2))
func = relay.Function(relay.analysis.free_vars(act),act)




# print(type(func))
# # mod = relay.Module.from_expr(expr)
# net = relay.Module.from_expr(func)


m = relay.Module()
m['main'] = func
net = relay.transform.InferType()(m)   # InferType ???


def create_workload(net, initializer=None, seed=0):
    """Helper function to create benchmark image classification workload.

    Parameters
    ----------
    net : tvm.relay.Function
        The selected function of the network.

    initializer : Initializer
        The initializer used

    seed : int
        The seed used in initialization.

    Returns
    -------
    mod : tvm.relay.Module
        The created relay module.

    params : dict of str to NDArray
        The parameters.
    """
    mod = relay.Module.from_expr(net)
    mod = relay.transform.InferType()(mod)
    shape_dict = {
        v.name_hint : v.checked_type for v in mod["main"].params}
    np.random.seed(seed)
    # initializer = initializer if initializer else Xavier()
    params = {}
    for k, v in shape_dict.items():
        if k == "data":
            continue
        init_value = np.random.uniform(-1, 1, v.concrete_shape).astype(v.dtype)
        # init_value = np.zeros(v.concrete_shape).astype(v.dtype)
        # initializer(k, init_value)
        params[k] = tvm.nd.array(init_value, ctx=tvm.cpu(0))
    return mod, params

# get module and params
mod,params = create_workload(m['main'])


target = "llvm"
ctx = tvm.context(target, 0)


# https://github.com/apache/incubator-tvm/blob/v0.6/src/relay/backend/build_module.cc

with relay.build_config(opt_level=3):
  graph, lib, params = relay.build(mod, target, params=params)

module = graph_runtime.create(graph, lib, ctx)
data_tvm = tvm.nd.array((np.random.uniform(-1, 1, size=data_shape)).astype(dtype))
module.set_input('data', data_tvm)
module.set_input(**params)

module.run()
output = module.get_output(0)

print(output)
print(output.shape)