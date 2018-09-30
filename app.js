/**
 * Copyright(C), 2018-2019, zhouzhi073859@outlook.com, chengdu, sichuang, China.
 * @module
 * @Author zhouzhi
 * @CreateTime
 * @Description
 * @Version
 * @FunctionList
 * @History
 */
const Tclass = require('./src/class/class');
const CallBack = require('./src/callback/callback');
CallBack.runCallBack(function (msg) {
  console.log(msg);
});

function testRecv(desiredRecv) {
  CallBack.runCallBackWithRecv(function() {
    console.log(this, desiredRecv);
  }, desiredRecv);
}

testRecv('Hello1');
