// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

void func(void) {
  float divident = 41.26, divisor = 29.3, result;

  int var, var2;

  divisor = 0.0;

  for (var = 0; var < 11; var++) {
    for (var2 = var; var2 < 13; var2++) {
      result = divident / divisor; // FLAW
    }
  }
}
