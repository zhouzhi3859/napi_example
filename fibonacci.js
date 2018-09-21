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

const fibonacci_a = n => {
  if (n < 2) {
    return n;
  }
  return fibonacci_a(n - 2) + fibonacci_a(n - 1);
};

const fibonacci_b = n => {
  let feb_n_val = 0;
  let a = 1;
  let b = 1;
  if (n < 3) {
    return 1;
  }
  for(let i = 3;i <= n;i++) {
    feb_n_val = a + b;
    b = a;
    a = feb_n_val;
  }
  return feb_n_val;
};

module.exports = {
  fibonacci_a, fibonacci_b,
};
