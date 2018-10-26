#include <iostream>
#include <utility>
#include "./function_wrap.h"

napi_value function::fib_a(napi_env env, napi_callback_info info) {
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

napi_value function::fib_b(napi_env env, napi_callback_info info) {
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

napi_value function::add(napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value args[2];
  napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

  napi_valuetype valuetype0;
  napi_typeof(env, args[0], &valuetype0);
  if (!(valuetype0 == napi_number)) {
    napi_value errChar;
    napi_throw_error(env, NULL, "assertion (Wrong argument type. Numbers expected.) failed");
    napi_create_string_utf8(env, "Wrong argument type. Numbers expected.", sizeof("Wrong argument type. Numbers expected."), &errChar);
    return  errChar;
  }

  napi_valuetype valuetype1;
  napi_typeof(env, args[1], &valuetype1);
  if (!(valuetype1 == napi_number)) {
    napi_value errChar;
    napi_throw_error(env, NULL, "assertion (Wrong argument type. Numbers expected.) failed");
    napi_create_string_utf8(env, "Wrong argument type. Numbers expected.", sizeof("Wrong argument type. Numbers expected."), &errChar);
    return  errChar;
  }

  double value0;
  napi_get_value_double(env, args[0], &value0);

  double value1;
  napi_get_value_double(env, args[1], &value1);

  double addRes = 0;
  addRes = value0 + value1;

  char str1[32];
  sprintf(str1,"%.10f",addRes);

  int eff_len = 0;

  for (int i = 0; i < 32; ++i) {
    if (str1[i] != '\0') {
      eff_len += 1;
    }
  }

  char* str2 = new char[ eff_len ];
  sprintf(str2,"%.10f",addRes);

  napi_value result;
  napi_create_string_utf8(env, &str2[0], sizeof(str2), &result);

  delete str2;
  return result;
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
