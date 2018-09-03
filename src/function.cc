#include <node_api.h>
#include <iostream>

static napi_value Sum(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1];
  napi_get_cb_info(env, info, &argc, args, NULL, NULL);

  napi_valuetype valuetype0;
  napi_typeof(env, args[0], &valuetype0);

  if (!(valuetype0 == napi_number)) {
    napi_value errChar;
    napi_throw_error(env, NULL, "assertion (Wrong argument type. Numbers expected.) failed");
    napi_create_string_utf8(env, "Wrong argument type. Numbers expected.", sizeof("Wrong argument type. Numbers expected."), &errChar);
    return  errChar;
  }

  long long int value0;
  napi_get_value_int64(env, args[0], &value0);

  long long int fbnqRes = 0;
  long i;
  for (i = 0; i <= value0; i++) {
    fbnqRes = fbnqRes + i;
  }

  napi_value result;
  napi_create_int64(env, fbnqRes, &result);

  return result;
}

static napi_value Init(napi_env env, napi_value exports) {
  napi_property_descriptor desc = { "sum", 0, Sum, 0, 0, 0, napi_default, 0 };
  napi_define_properties(env, exports, 1, &desc);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
