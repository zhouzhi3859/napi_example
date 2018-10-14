{
  "targets": [
     {
       "target_name": "<(module_name)",
       "sources": [ "./src/callback/callback.cc", "./src/function/function.cc", "./src/class/class.cc", "./src/napi_example.cc" ]
     },
    {
      "target_name": "action_after_build",
      "type": "none",
      "dependencies": [ "<(module_name)" ],
      "copies": [
        {
          "files": [ "<(PRODUCT_DIR)/<(module_name).node" ],
          "destination": "<(module_path)"
        }
      ]
    }
  ],
  "defines": [
      "NAPI_VERSION=<(napi_build_version)",
  ]
}
