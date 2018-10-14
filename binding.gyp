{
  "targets": [
     {
       "target_name": "callback",
       "sources": [ "./src/callback/callback.cc" ]
     },
    {
      "target_name": "class",
      "sources": [ "./src/class/class.cc" ]
    },
    {
      "target_name": "function",
      "sources": [ "./src/function/function.cc" ]
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
