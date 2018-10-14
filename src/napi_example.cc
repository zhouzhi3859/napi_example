//
// Created by zhouz on 2018/10/14.
//
#include "./class/class.h"
#include "./callback/callback.h"
#include "./function/function.h"
//using namespace function;
napi_value Init(napi_env env, napi_value exports) {
  napi_property_descriptor properties[] = {
      { "value", nullptr, nullptr, MyObject::GetValue, MyObject::SetValue, 0, napi_default, 0 },
      { "plusOne", 0, MyObject::PlusOne, 0, 0, 0, napi_default, 0 },
      { "multiply", 0, MyObject::Multiply, 0, 0, 0, napi_default, 0 },
  };

  napi_value cons;
  napi_define_class(env, "MyObject", -1, MyObject::New, nullptr, 3, properties, &cons);

  napi_create_reference(env, cons, 1, &MyObject::constructor);
  napi_property_descriptor desc[4] = {
      { "runCallBack", 0, callback::RunCallBack, nullptr, nullptr, nullptr, napi_default, nullptr },
      { "runCallBackWithRecv", 0, callback::RunCallBackWithRecv, nullptr, nullptr, nullptr, napi_default, nullptr },
      { "fib_a", 0, function::fib_a, 0, 0, 0, napi_default, 0 },
      { "fib_b", 0, function::fib_b, 0, 0, 0, napi_default, 0 },
  };
  napi_define_properties(env, exports, 4, desc);
  napi_set_named_property(env, exports, "MyObject", cons);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
