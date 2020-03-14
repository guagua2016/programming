Relay module function:
 v0.0.4
def @main(%data: Tensor[(1, 3, 224, 224), float32], %graph_conv_weight: Tensor[(32, 3, 3, 3), float32], %graph_bn_gamma: Tensor[(32), float32], %graph_bn_beta: Tensor[(32), float32], %graph_bn_moving_mean: Tensor[(32), float32], %graph_bn_moving_var: Tensor[(32), float32]) -> Tensor[(1, 32, 112, 112), float32] {
  %0 = nn.conv2d(%data, %graph_conv_weight, strides=[2, 2], padding=[1, 1], channels=32, kernel_size=[3, 3]) /* ty=Tensor[(1, 32, 112, 112), float32] */;
  %1 = nn.batch_norm(%0, %graph_bn_gamma, %graph_bn_beta, %graph_bn_moving_mean, %graph_bn_moving_var) /* ty=(Tensor[(1, 32, 112, 112), float32], Tensor[(32), float32], Tensor[(32), float32]) */;
  %2 = %1.0;
  nn.relu(%2) /* ty=Tensor[(1, 32, 112, 112), float32] */
}

TVM parameters:
 dict_keys(['graph_conv_weight', 'graph_bn_gamma', 'graph_bn_beta', 'graph_bn_moving_mean', 'graph_bn_moving_var'])
TVM graph:
 {
  "nodes": [
    {
      "op": "null", 
      "name": "data", 
      "inputs": []
    }, 
    {
      "op": "tvm_op", 
      "name": "fused_layout_transform_3", 
      "attrs": {
        "num_outputs": "1", 
        "num_inputs": "1", 
        "func_name": "fused_layout_transform_3", 
        "flatten_data": "0"
      }, 
      "inputs": [
        [
          0, 
          0, 
          0
        ]
      ]
    }, 
    {
      "op": "null", 
      "name": "p0", 
      "inputs": []
    }, 
    {
      "op": "null", 
      "name": "p1", 
      "inputs": []
    }, 
    {
      "op": "tvm_op", 
      "name": "fused_nn_contrib_conv2d_NCHWc_add_nn_relu", 
      "attrs": {
        "num_outputs": "1", 
        "num_inputs": "3", 
        "func_name": "fused_nn_contrib_conv2d_NCHWc_add_nn_relu", 
        "flatten_data": "0"
      }, 
      "inputs": [
        [
          1, 
          0, 
          0
        ], 
        [
          2, 
          0, 
          0
        ], 
        [
          3, 
          0, 
          0
        ]
      ]
    }, 
    {
      "op": "tvm_op", 
      "name": "fused_layout_transform_2", 
      "attrs": {
        "num_outputs": "1", 
        "num_inputs": "1", 
        "func_name": "fused_layout_transform_2", 
        "flatten_data": "0"
      }, 
      "inputs": [
        [
          4, 
          0, 
          0
        ]
      ]
    }
  ], 
  "arg_nodes": [0, 2, 3], 
  "heads": [
    [
      5, 
      0, 
      0
    ]
  ], 
  "attrs": {
    "dltype": [
      "list_str", 
      [
        "float32", 
        "float32", 
        "float32", 
        "float32", 
        "float32", 
        "float32"
      ]
    ], 
    "shape": [
      "list_shape", 
      [
        [1, 3, 224, 224], 
        [1, 1, 224, 224, 3], 
        [4, 1, 3, 3, 3, 8], 
        [1, 4, 1, 1, 8], 
        [1, 4, 112, 112, 8], 
        [1, 32, 112, 112]
      ]
    ], 
    "storage_id": [
      "list_int", 
      [0, 1, 2, 3, 4, 1]
    ]
  }, 
  "node_row_ptr": [0, 1, 2, 3, 4, 5, 6]
}
TVM parameters:
 dict_keys(['p1', 'p0'])
