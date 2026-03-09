// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

void func(void) {
  int divident = 16, divisor = 7, result;
  int var_a = 120;
  int var_b = 126;

  int var, var2;

  divisor = var_a - var_b;

  for (var = 0; var < 17; var++) {
    for (var2 = var; var2 < 10; var2++) {
      result = divident / divisor;
    }
  }
}
