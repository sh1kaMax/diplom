// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

void func(void) {
  int iter_var;

  float divident = 66.11, divisor = 13.43, result;

  for (iter_var = 1; iter_var < 30; iter_var++) {
    divisor = 0.0;

    result = divident / divisor; // FLAW
  }
}
