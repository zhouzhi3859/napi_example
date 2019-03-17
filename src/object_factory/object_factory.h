//
// Created by zhouz on 2018/11/1.
//

#ifndef NAPI_EXAMPLE_OBJECT_FACTORY_H
#define NAPI_EXAMPLE_OBJECT_FACTORY_H

#include <node_api.h>

namespace object_factory {
  napi_value CreateObject(napi_env env, napi_callback_info info);
}

#endif //NAPI_EXAMPLE_OBJECT_FACTORY_H
