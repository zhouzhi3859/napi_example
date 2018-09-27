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
const Tclass = require('./class');
const functions = require('./function');
const fibonacci = require('./fibonacci');
const nowTime1 = Date.now();
const result1 = functions.fib_a(40);
console.log('compute in recursion with napi module: ' + result1 + ',expend ' + ((Date.now()) - nowTime1) + ' ms');
const nowTime2 = Date.now();
const result2 = functions.fib_b(1000000);
console.log('compute in loop with napi module: ' + result2 + ',expend ' + ((Date.now()) - nowTime2) + ' ms');
const nowTime3 = Date.now();
const result3 = fibonacci.fibonacci_a(40);
console.log('compute in recursion with js module: ' + result3 + ',expend ' + ((Date.now()) - nowTime3) + ' ms');
const nowTime4 = Date.now();
const result4 = fibonacci.fibonacci_b(40);
console.log('compute in loop with js module: ' + result4 + ',expend ' + ((Date.now()) - nowTime4) + ' ms');

