/* DO NOT EDIT THIS FILE - it is machine generated */

/* Copyright 2017, Emmanouil Antonios Platanios. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#include "tensor_text_ops.h"

#include <algorithm>
#include <cstring>
#include <memory>
#include <sstream>

#include "c_api.h"
#include "c_eager_api.h"
#include "exception_jni.h"
#include "utilities.h"

JNIEXPORT jlong JNICALL Java_org_platanios_tensorflow_jni_generated_tensors_Text_00024_stringJoin(
    JNIEnv* env, jobject object, jlong context_handle, jlongArray inputs, jbyteArray separator) {
  REQUIRE_HANDLE(context, TFE_Context, context_handle, 0);
  std::unique_ptr<TF_Status, decltype(&TF_DeleteStatus)> status(TF_NewStatus(), TF_DeleteStatus);

  std::unique_ptr<TFE_Op, decltype(&TFE_DeleteOp)> op(
      TFE_NewOp(context, "StringJoin", status.get()), TFE_DeleteOp);
  CHECK_STATUS(env, status.get(), 0);

  const int inputs_num_tensors = env->GetArrayLength(inputs);
  jlong *inputs_elems = env->GetLongArrayElements(inputs, nullptr);
  for (int i = 0; i < inputs_num_tensors; ++i) {
    REQUIRE_HANDLE(tensor_handle, TFE_TensorHandle, inputs_elems[i], 0);
    TFE_OpAddInput(op.get(), tensor_handle, status.get());
    CHECK_STATUS(env, status.get(), 0);
  }
  env->ReleaseLongArrayElements(inputs, inputs_elems, JNI_ABORT);

  const int attr_N = env->GetArrayLength(inputs);
  TFE_OpSetAttrInt(op.get(), "N", static_cast<int64_t>(attr_N));

  jbyte *separator_c_value = env->GetByteArrayElements(separator, nullptr);
  TFE_OpSetAttrString(op.get(), "separator", reinterpret_cast<const char *>(separator_c_value));
  env->ReleaseByteArrayElements(separator, separator_c_value, JNI_ABORT);

  const int num_outputs = 1;
  std::unique_ptr<TFE_TensorHandle* []> outputs(new TFE_TensorHandle* [num_outputs]);
  std::unique_ptr<int[]> actual_num_outputs(new int[1] {1});
  TFE_Execute(op.get(), outputs.get(), actual_num_outputs.get(), status.get());
  CHECK_STATUS(env, status.get(), 0);

  return reinterpret_cast<jlong>(outputs[0]);
}
