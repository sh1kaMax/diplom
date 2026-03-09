// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-mul_zero-div_op.json
//
// Нулевое значение получается как результат умножения.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 63, divisor = 10, result;
  int var_a = 0;

  int func_res = ret_func(10);

  if (param + func_res > 33) {
    divisor = param * var_a;
  }

  if (param + func_res > 33) {
    result = divident / divisor; // FLAW
  }
}
