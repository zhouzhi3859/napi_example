//
// Created by zhouz on 2018/10/14.
//

#ifndef NAPI_EXAMPLE_CALLBACK_H
#define NAPI_EXAMPLE_CALLBACK_H

#include <node_api.h>
namespace callback {
  napi_value RunCallBack(napi_env env, napi_callback_info info);
  napi_value RunCallBackWithRecv(napi_env env, napi_callback_info info);
}
#endif //NAPI_EXAMPLE_CALLBACK_H
