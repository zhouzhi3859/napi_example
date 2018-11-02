//
// Created by zhouz on 2018/11/2.
//

#include "passing_wrap.h"

MyObject2::MyObject2(): _env(nullptr), _wrapper(nullptr) {}

MyObject2::~MyObject2() {
  napi_delete_reference(_env, _wrapper);
}

napi_ref MyObject2::constructor;

void MyObject2::Destructor(
  napi_env env, void* nativeObject, void* /*finalize_hint*/) {
  MyObject2* obj = static_cast<MyObject2*>(nativeObject);
  delete obj;
}

napi_status MyObject2::Init(napi_env env) {
  napi_status status;
  
  napi_value cons;
  status = napi_define_class(env, "MyObject2", -1, New, nullptr, 0, nullptr, &cons);
  if (status != napi_ok) return status;
  
  status = napi_create_reference(env, cons, 1, &constructor);
  if (status != napi_ok) return status;
  
  return napi_ok;
}

napi_value MyObject2::New(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1];
  napi_value _this;
  
  napi_get_cb_info(env, info, &argc, args, &_this, nullptr);
  
  MyObject2* obj = new MyObject2();
  
  napi_valuetype valuetype;
  napi_typeof(env, args[0], &valuetype);
  
  if (valuetype == napi_undefined) {
    obj->_val = 0;
  } else {
    napi_get_value_double(env, args[0], &obj->_val);
  }
  
  obj->_env = env;
  
  napi_wrap(env, _this, obj, Destructor, nullptr, &obj->_wrapper);
  
  return _this;
}

napi_status MyObject2::NewInstance(napi_env env, napi_value arg, napi_value* instance) {
  napi_status status;
  const int argc = 1;
  napi_value argv[argc] = {arg};
  
  napi_value cons;
  status = napi_get_reference_value(env, constructor, &cons);
  if (status != napi_ok) return status;
  
  status = napi_new_instance(env, cons, argc, &argv[0], instance);
  if (status != napi_ok) return status;
  
  return napi_ok;
}

napi_value passing_wrap::CreateObject(napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value args[2];
  napi_get_cb_info(env, info, &argc, &args[0], nullptr, nullptr);
  
  napi_valuetype valuetype1;
  napi_typeof(env, args[0], &valuetype1);
  
  if (valuetype1 != napi_number) {
    napi_value errChar1;
    napi_throw_error(env, nullptr, "Wrong type of arguments. Expects a function_wrap as first argument.");
    napi_create_string_utf8(env, "Wrong type of arguments. Expects a function_wrap as first argument.",
                            sizeof("Wrong type of arguments. Expects a function_wrap as first argument."), &errChar1);
    return errChar1;
  }
  
  napi_valuetype valuetype2;
  napi_typeof(env, args[1], &valuetype2);
  
  if (valuetype2 != napi_undefined) {
    napi_value errChar2;
    napi_throw_error(env, nullptr, "Additional arguments should be undefined.");
    napi_create_string_utf8(env, "Additional arguments should be undefined.", sizeof("Additional arguments should be undefined."), &errChar2);
    return errChar2;
  }
  
  napi_value instance;
  MyObject2::NewInstance(env, args[0], &instance);
  
  return instance;
}
