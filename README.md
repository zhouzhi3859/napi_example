# napi_example

This is a repository of node napi examples.\
If you want detail of napi, you can visit [node_napi].

# Table of Contents
* [callback](src/callback/callback.cc)
* [function_wrap](src/function_wrap/function_wrap.cc)
* [object_wrap](src/object_wrap/object_wrap.cc)
* [object_factory](src/object_factory/object_factory.cc)

# Where napi_module used
You can visit [app.js](./app.js) know how use it which napi_module are constructed.

# Run this example
You have to make sure [node_gyp] now installed in you computer.
```shell
npm install
npm run build
npm run dev
```

[node_napi]:http://nodejs.cn/api/n-api.html
[node_gyp]:https://www.npmjs.com/package/node-gyp


