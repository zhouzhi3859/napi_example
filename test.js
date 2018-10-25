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
console.log('script start');

setTimeout(function() {
  console.log('timeout1');
}, 10);

new Promise((resolve) => {
  console.log('promise1');
  resolve();
  setTimeout(() => {
    console.log('timeout2');
  }, 10);
  setTimeout(() => {
    console.log('timeout3');
  }, 0);
  setImmediate(() => {
    console.log('immediate');
  });
  process.nextTick(() => {
    console.log('then2');
  });
}).then(function() {
  console.log('then1');
});

console.log('script end');
