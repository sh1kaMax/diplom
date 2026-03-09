// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

void func(void) {
  int divident = 17, divisor = 3, result;
  int var_a = 125;
  int var_b = 125;

  int var, var2;

  divisor = var_a - var_b;

  for (var = 0; var < 17; var++) {
    for (var2 = var; var2 < 17; var2++) {
      result = divident / divisor; // FLAW
    }
  }
}
