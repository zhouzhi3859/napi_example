//
// Created by zhouz on 2018/10/14.
//

#ifndef NAPI_EXAMPLE_FUNCTION_H
#define NAPI_EXAMPLE_FUNCTION_H
#include <node_api.h>

long fibonacci_a(int n);
long fibonacci_b(int &n);
namespace function {

  napi_value fib_a(napi_env env, napi_callback_info info);

  napi_value fib_b(napi_env env, napi_callback_info info);

  napi_value add(napi_env env, napi_callback_info info);
}
#endif //NAPI_EXAMPLE_FUNCTION_H
