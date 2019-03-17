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
const binary = require('node-pre-gyp');
const path = require('path');
const binding_path = binary.find(path.resolve(path.join(__dirname, '../package.json')));
const binding = require(binding_path);

module.exports = binding;
