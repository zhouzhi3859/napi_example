//
// Created by zhouz on 2018/8/1.
//
#include "./class.h"

napi_ref MyObject::constructor;

MyObject::MyObject(double value)
        : value_(value), env_(nullptr), wrapper_(nullptr) {}

MyObject::~MyObject() { napi_delete_reference(env_, wrapper_); }

void MyObject::Destructor(
        napi_env env, void* nativeObject, void* /*finalize_hint*/) {
    MyObject* obj = static_cast<MyObject*>(nativeObject);
    delete obj;
}

void MyObject::Init(napi_env env, napi_value exports) {
    napi_property_descriptor properties[] = {
            { "value", nullptr, nullptr, GetValue, SetValue, 0, napi_default, 0 },
            { "plusOne", 0, PlusOne, 0, 0, 0, napi_default, 0 },
            { "multiply", 0, Multiply, 0, 0, 0, napi_default, 0 },
    };

    napi_value cons;
    napi_define_class(
            env, "MyObject", -1, New, nullptr, 3, properties, &cons);

    napi_create_reference(env, cons, 1, &constructor);

    napi_set_named_property(env, exports, "MyObject", cons);
}

napi_value MyObject::New(napi_env env, napi_callback_info info) {
    napi_value new_target;
    napi_get_new_target(env, info, &new_target);
    bool is_constructor = (new_target != nullptr);

    size_t argc = 1;
    napi_value args[1];
    napi_value _this;
    napi_get_cb_info(env, info, &argc, args, &_this, nullptr);

    if (is_constructor) {
        // Invoked as constructor: `new MyObject(...)`
        double value = 0;

        napi_valuetype valuetype;
        napi_typeof(env, args[0], &valuetype);

        if (valuetype != napi_undefined) {
            napi_get_value_double(env, args[0], &value);
        }

        MyObject* obj = new MyObject(value);

        obj->env_ = env;
        napi_wrap(env,
                  _this,
                  obj,
                  MyObject::Destructor,
                  nullptr,  // finalize_hint
                  &obj->wrapper_);

        return _this;
    }

    // Invoked as plain function `MyObject(...)`, turn into construct call.
    argc = 1;
    napi_value argv[1] = {args[0]};

    napi_value cons;
    napi_get_reference_value(env, constructor, &cons);

    napi_value instance;
    napi_new_instance(env, cons, argc, argv, &instance);

    return instance;
}

napi_value MyObject::GetValue(napi_env env, napi_callback_info info) {
    napi_value _this;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);

    MyObject* obj;
    napi_unwrap(env, _this, reinterpret_cast<void**>(&obj));

    napi_value num;
    napi_create_double(env, obj->value_, &num);

    return num;
}

napi_value MyObject::SetValue(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_value _this;
    napi_get_cb_info(env, info, &argc, args, &_this, nullptr);

    MyObject* obj;
    napi_unwrap(env, _this, reinterpret_cast<void**>(&obj));

    napi_get_value_double(env, args[0], &obj->value_);

    return nullptr;
}

napi_value MyObject::PlusOne(napi_env env, napi_callback_info info) {
    napi_value _this;
    napi_get_cb_info(env, info, nullptr, nullptr, &_this, nullptr);

    MyObject* obj;
    napi_unwrap(env, _this, reinterpret_cast<void**>(&obj));

    obj->value_ += 1;

    napi_value num;
    napi_create_double(env, obj->value_, &num);

    return num;
}

napi_value MyObject::Multiply(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_value _this;
    napi_get_cb_info(env, info, &argc, args, &_this, nullptr);

    double multiple = 1;
    if (argc >= 1) {
        napi_get_value_double(env, args[0], &multiple);
    }

    MyObject* obj;
    napi_unwrap(env, _this, reinterpret_cast<void**>(&obj));

    napi_value cons;
    napi_get_reference_value(env, constructor, &cons);

    const int kArgCount = 1;
    napi_value argv[kArgCount];
    napi_create_double(env, obj->value_ * multiple, argv);

    napi_value instance;
    napi_new_instance(env, cons, kArgCount, argv, &instance);

    return instance;
}
