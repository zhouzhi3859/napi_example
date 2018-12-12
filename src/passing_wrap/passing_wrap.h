//
// Created by zhouz on 2018/11/2.
//

#ifndef NAPI_EXAMPLE_PASSING_WRAP_H
#define NAPI_EXAMPLE_PASSING_WRAP_H
#include <node_api.h>

namespace passing_wrap {
  napi_value CreateObject(napi_env env, napi_callback_info info);
}
class MyObject2 {
private:
  MyObject2();
  ~MyObject2();
  double _val;
  
  static napi_ref constructor;
  napi_env _env;
  napi_ref _wrapper;
  static void Destructor(napi_env env, void* nativeObject, void* finalize_hint);
  
public:
  static napi_status Init(napi_env env);
  static napi_value New(napi_env env, napi_callback_info info);
  static napi_status NewInstance(napi_env env, napi_value arg, napi_value* instance);
};

#endif //NAPI_EXAMPLE_PASSING_WRAP_H
