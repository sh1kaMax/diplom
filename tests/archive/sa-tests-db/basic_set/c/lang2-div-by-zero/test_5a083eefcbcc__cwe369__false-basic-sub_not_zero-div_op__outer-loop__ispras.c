// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

void func(void) {
  int iter_var;

  int divident = 37, divisor = 10, result;
  int var_a = 84;
  int var_b = 93;

  for (iter_var = 5; iter_var < 12; iter_var++) {
    divisor = var_a - var_b;

    result = divident / divisor;
  }
}
