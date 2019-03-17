//
// Created by zhouz on 2018/10/14.
//
#include "object_wrap/object_wrap.h"
#include "object_factory/object_factory.h"
#include "callback/callback.h"
#include "function_wrap/function_wrap.h"
#include "passing_wrap/passing_wrap.h"
napi_value Init(napi_env env, napi_value exports) {
  napi_property_descriptor properties[] = {
    { "value", nullptr, nullptr, MyObject1::GetValue, MyObject1::SetValue, 0, napi_default, 0 },
    { "plusOne", 0, MyObject1::PlusOne, 0, 0, 0, napi_default, 0 },
    { "multiply", 0, MyObject1::Multiply, 0, 0, 0, napi_default, 0 },
  };

  napi_value cons1;
  napi_define_class(env, "MyObject1", -1, MyObject1::New, nullptr, 3, properties, &cons1);
  napi_create_reference(env, cons1, 1, &MyObject1::constructor);
  
  MyObject2::Init(env);
  
  napi_property_descriptor desc[7] = {
    { "runCallBack", 0, callback::RunCallBack, nullptr, nullptr, nullptr, napi_default, nullptr },
    { "runCallBackWithRecv", 0, callback::RunCallBackWithRecv, nullptr, nullptr, nullptr, napi_default, nullptr },
    { "fib_a", 0, function_wrap::fib_a, nullptr, nullptr, nullptr, napi_default, nullptr },
    { "fib_b", 0, function_wrap::fib_b, nullptr, nullptr, nullptr, napi_default, nullptr },
    { "add", 0, function_wrap::add, nullptr, nullptr, nullptr, napi_default, nullptr },
    { "createObject1", 0, object_factory::CreateObject, nullptr, nullptr, nullptr, napi_default, nullptr },
    { "createObject2", 0, passing_wrap::CreateObject, nullptr, nullptr, nullptr, napi_default, nullptr },
  };
  napi_define_properties(env, exports, 7, desc);
  napi_set_named_property(env, exports, "MyObject1", cons1);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
