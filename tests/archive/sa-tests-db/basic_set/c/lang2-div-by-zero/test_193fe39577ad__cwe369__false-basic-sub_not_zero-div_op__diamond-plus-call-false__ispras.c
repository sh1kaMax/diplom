// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 64, divisor = 4, result;
  int var_a = 38;
  int var_b = 44;

  int func_res = ret_func(10);

  if (param + func_res > 40) {
    divisor = var_a - var_b;
  }

  if (param + func_res < 40) {
    result = divident / divisor;
  }
}
