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

const binding = require('./src');
const obj = new binding.MyObject(9);
console.log(binding.fib_a(40),);
console.log(obj.plusOne());
binding.runCallBack(function (msg) {
  console.log(msg);
});

function testRecv(desiredRecv) {
  binding.runCallBackWithRecv(function() {
    console.log(this, desiredRecv);
  }, desiredRecv);
}

testRecv('Hello1');
