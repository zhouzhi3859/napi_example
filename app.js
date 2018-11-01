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
console.log(binding.fib_a(40));

const obj1 = new binding.MyObject(9);
console.log(obj1.plusOne());

const obj2 = binding.createObject('obj2');
console.log('obj2.msg', obj2.msg);

binding.runCallBack(function(msg) {
  console.log('runCallBack', msg);
});

const testRecv = function(desiredRecv) {
  binding.runCallBackWithRecv(function() {
    console.log(this, desiredRecv);
  }, desiredRecv);
};

testRecv('Hello1');
const a1 = 2731723712n;
const b1 = 2731723712n;
console.log(a1 * b1);

const a2 = 2731723712;
const b2 = 2731723712;
console.log(a2 * b2);

const a3 = 0.01;
const b3 = 0.09;
console.log(a3 + b3);

let res = binding.add(0.01, 0.09);

console.log(Number(res));
