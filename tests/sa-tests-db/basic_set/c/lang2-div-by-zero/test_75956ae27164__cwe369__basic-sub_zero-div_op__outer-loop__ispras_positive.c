// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

void func(void) {
  int iter_var;

  int divident = 68, divisor = 10, result;
  int var_a = 152;
  int var_b = 152;

  for (iter_var = 5; iter_var < 20; iter_var++) {
    divisor = var_a - var_b;

    result = divident / divisor; // FLAW
  }
}
