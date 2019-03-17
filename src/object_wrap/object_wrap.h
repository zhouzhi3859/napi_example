#ifndef TEST_ADDONS_NAPI_6_OBJECT_WRAP_MyObject1_H_
#define TEST_ADDONS_NAPI_6_OBJECT_WRAP_MyObject1_H_

#include <node_api.h>

class MyObject1 {
 public:
  static void Init(napi_env env, napi_value exports);
  static void Destructor(napi_env env, void* nativeObject, void* finalize_hint);

public:
  explicit MyObject1(double value_ = 0);
  ~MyObject1();

  static napi_value New(napi_env env, napi_callback_info info);
  static napi_value GetValue(napi_env env, napi_callback_info info);
  static napi_value SetValue(napi_env env, napi_callback_info info);
  static napi_value PlusOne(napi_env env, napi_callback_info info);
  static napi_value Multiply(napi_env env, napi_callback_info info);
  static napi_ref constructor;
  double value_;
  napi_env env_;
  napi_ref wrapper_;
};
#endif  // TEST_ADDONS_NAPI_6_OBJECT_WRAP_MyObject1_H_

