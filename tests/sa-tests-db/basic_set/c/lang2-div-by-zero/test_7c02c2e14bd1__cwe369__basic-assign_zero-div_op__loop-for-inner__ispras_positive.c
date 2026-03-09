// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-div_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

void func(void) {
  int divident = 49, divisor = 3, result;

  int var, var2;

  divisor = 0;

  for (var = 0; var < 19; var++) {
    for (var2 = var; var2 < 12; var2++) {
      result = divident / divisor; // FLAW
    }
  }
}
