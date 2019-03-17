
//#include <string.h>
#include "callback.h"
//using namespace callback;
napi_value callback::RunCallBack(napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value args[2];
//  napi_get_cb_info(env, info, &argc, &args[0], nullptr, nullptr);
  napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

  napi_valuetype valuetype0;
  napi_typeof(env, args[0], &valuetype0);

  if (valuetype0 != napi_function) {
    napi_value errChar1;
    napi_throw_error(env, nullptr, "Wrong type of arguments. Expects a function_wrap as first argument.");
    napi_create_string_utf8(env, "Wrong arguments. Expects a function_wrap as first argument.",
      sizeof("Wrong arguments. Expects a function_wrap as first argument."), &errChar1);
    return  errChar1;
  }

  napi_valuetype valuetype1;
  napi_typeof(env, args[1], &valuetype1);
  if (valuetype1 != napi_undefined) {
    napi_value errChar2;
    napi_throw_error(env, nullptr, "Additional arguments should be undefined.");
    napi_create_string_utf8(env, "Wrong arguments. Additional arguments should be undefined.", sizeof("Wrong arguments. Additional arguments should be undefined."), &errChar2);
    return  errChar2;
  }

//  napi_value argv;
//  const char* str = "hello world";
//  size_t str_len = strlen(str);
//  napi_create_string_utf8(env, str, str_len, &argv);

  napi_value argv[1];
//  napi_create_string_utf8(env, "hello world", sizeof("hello world"), &argv[0]);
  napi_create_string_utf8(env, "hello world", sizeof("hello world"), argv);

  napi_value global;
  napi_get_global(env, &global);

  napi_value cb = args[0];
  napi_call_function(env, global, cb, 1, argv, nullptr);

  return nullptr;
}

napi_value callback::RunCallBackWithRecv(napi_env env, napi_callback_info info) {
  size_t argc = 3;
  napi_value args[3];
  napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

  napi_valuetype valuetype0;
  napi_typeof(env, args[0], &valuetype0);

  if (valuetype0 != napi_function) {
    napi_value errChar1;
    napi_throw_error(env, nullptr, "Wrong type of arguments. Expects a function_wrap as first argument.");
    napi_create_string_utf8(env, "Wrong arguments. Expects a function_wrap as first argument.",
      sizeof("Wrong arguments. Expects a function_wrap as first argument."), &errChar1);
    return  errChar1;
  }

  napi_valuetype valuetype1;
  napi_typeof(env, args[1], &valuetype1);

  if (valuetype1 != napi_string) {
    napi_value errChar2;
    napi_throw_error(env, nullptr, "Wrong type of arguments. Expects a string as second argument.");
    napi_create_string_utf8(env, "Wrong arguments. Expects a string as second argument.",
      sizeof("Wrong arguments. Expects a string as second argument."), &errChar2);
    return  errChar2;
  }

  napi_valuetype valuetype2;
  napi_typeof(env, args[2], &valuetype2);
  if (valuetype2 != napi_undefined) {
    napi_value errChar3;
    napi_throw_error(env, nullptr, "Additional arguments should be undefined.");
    napi_create_string_utf8(env, "Wrong arguments. Additional arguments should be undefined.",
      sizeof("Wrong arguments. Additional arguments should be undefined."), &errChar3);
    return  errChar3;
  }

  napi_value cb = args[0];
  napi_value recv = args[1];
  napi_call_function(env, recv, cb, 0, nullptr, nullptr);

  return nullptr;
}

