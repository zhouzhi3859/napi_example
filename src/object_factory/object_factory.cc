//
// Created by zhouz on 2018/11/1.
//

#include "object_factory.h"

napi_value object_factory::CreateObject(napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value args[2];
  napi_get_cb_info(env, info, &argc, &args[0], nullptr, nullptr);
  
  napi_valuetype valuetype0;
  napi_typeof(env, args[0], &valuetype0);
  
  if (valuetype0 != napi_string) {
    napi_value errChar1;
    napi_throw_error(env, nullptr, "Wrong type of arguments. Expects a function_wrap as first argument.");
    napi_create_string_utf8(env, "Wrong type of arguments. Expects a function_wrap as first argument.",
      sizeof("Wrong type of arguments. Expects a function_wrap as first argument."), &errChar1);
    
    return errChar1;
  }
  
  napi_valuetype valuetype1;
  napi_typeof(env, args[1], &valuetype1);
  
  if (valuetype1 != napi_undefined) {
    napi_value errChar2;
    napi_throw_error(env, nullptr, "Additional arguments should be undefined.");
    napi_create_string_utf8(env, "Additional arguments should be undefined.",
      sizeof("Additional arguments should be undefined."), &errChar2);
    
    return errChar2;
  }
  
  napi_value obj;
  napi_create_object(env, &obj);
  napi_set_named_property(env, obj, "msg", args[0]);
  
  return obj;
}
