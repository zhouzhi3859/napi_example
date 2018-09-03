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
const nowTime = Date.now();
const result = functions.sum(100000);
console.log('结果为：' + result + '，耗时' + ((Date.now()) - nowTime) + 'ms');
