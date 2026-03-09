// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 44, divisor = 8, result;
  int var_a = 155;
  int var_b = 155;

  int func_res = ret_func(10);

  if (param + func_res > 25) {
    divisor = var_a - var_b;
  }

  if (param + func_res < 25) {
    result = divident / divisor;
  }
}
