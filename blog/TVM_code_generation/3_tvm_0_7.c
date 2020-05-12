#include "tvm/runtime/c_runtime_api.h"
#include "tvm/runtime/c_backend_api.h"
extern void* __tvm_module_ctx = NULL;

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t mmult(void* args, void* arg_type_ids, int32_t num_args, void* out_ret_value, void* out_ret_tcode) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int32_t arg0_code = ((int32_t*)arg_type_ids)[(0)];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int32_t arg1_code = ((int32_t*)arg_type_ids)[(1)];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int32_t arg2_code = ((int32_t*)arg_type_ids)[(2)];
  void* A = (((DLTensor*)arg0)[0].data);
  void* arg0_shape = (((DLTensor*)arg0)[0].shape);
  void* arg0_strides = (((DLTensor*)arg0)[0].strides);
  int32_t dev_id = (((DLTensor*)arg0)[0].ctx.device_id);
  void* B = (((DLTensor*)arg1)[0].data);
  void* arg1_shape = (((DLTensor*)arg1)[0].shape);
  void* arg1_strides = (((DLTensor*)arg1)[0].strides);
  void* C = (((DLTensor*)arg2)[0].data);
  void* arg2_shape = (((DLTensor*)arg2)[0].shape);
  void* arg2_strides = (((DLTensor*)arg2)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  if (!(arg1_strides == NULL)) {
  }
  if (!(arg2_strides == NULL)) {
  }
  for (int32_t x = 0; x < 1024; ++x) {
    for (int32_t y = 0; y < 1024; ++y) {
      ((float*)C)[(((x * 1024) + y))] = 0.000000e+00f;
      for (int32_t k = 0; k < 1024; ++k) {
        ((float*)C)[(((x * 1024) + y))] = (((float*)C)[(((x * 1024) + y))] + (((float*)A)[(((x * 1024) + k))] * ((float*)B)[(((k * 1024) + y))]));
      }
    }
  }
  return 0;
}
