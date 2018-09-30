#include <node_api.h>

long fibonacci_a(int n);
long fibonacci_b(int &n);

static napi_value fib_a(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1];
  napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

  napi_valuetype valuetype0;
  napi_typeof(env, args[0], &valuetype0);

  if (!(valuetype0 == napi_number)) {
    napi_value errChar;
    napi_throw_error(env, nullptr, "assertion (Wrong argument type. Numbers expected.) failed");
    napi_create_string_utf8(env, "Wrong argument type. Numbers expected.",
        sizeof("Wrong argument type. Numbers expected."), &errChar);
    return  errChar;
  }

  int value0;
  napi_get_value_int32(env, args[0], &value0);

  long fbnqRes = 0;
  fbnqRes = fibonacci_a(value0);

  napi_value result;
  napi_create_int32(env, fbnqRes, &result);

  return result;
}

static napi_value fib_b(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1];
  napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

  napi_valuetype valuetype0;
  napi_typeof(env, args[0], &valuetype0);

  if (!(valuetype0 == napi_number)) {
    napi_value errChar;
    napi_throw_error(env, NULL, "assertion (Wrong argument type. Numbers expected.) failed");
    napi_create_string_utf8(env, "Wrong argument type. Numbers expected.", sizeof("Wrong argument type. Numbers expected."), &errChar);
    return  errChar;
  }

  int value0;
  napi_get_value_int32(env, args[0], &value0);

  long fbnqRes = 0;
  fbnqRes = fibonacci_b(value0);

  napi_value result;
  napi_create_int32(env, fbnqRes, &result);

  return result;
}

static napi_value Init(napi_env env, napi_value exports) {
  napi_property_descriptor desc[2] = {
    { "fib_a", 0, fib_a, 0, 0, 0, napi_default, 0 },
    { "fib_b", 0, fib_b, 0, 0, 0, napi_default, 0 },
  };
  napi_define_properties(env, exports, 2, desc);
  return exports;
}


long fibonacci_a(int n) {
  if (n < 2) {
    return n;
  }
  return fibonacci_a(n - 2) + fibonacci_a(n - 1);
}

long fibonacci_b(int &n) {
  long feb_n_val = 0;
  int i;
  long a = 1;
  long b = 1;
  if (n < 3) {
    return 1;
  }
  for(i = 3;i <= n;i++) {
    feb_n_val = a + b;
    b = a;
    a = feb_n_val;
  }
  return feb_n_val;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
