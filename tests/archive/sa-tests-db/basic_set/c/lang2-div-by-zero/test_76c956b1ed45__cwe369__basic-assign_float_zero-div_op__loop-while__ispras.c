// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

void func(void) {
  float divident = 8.0, divisor = 28.48, result;

  int var;

  divisor = 0.0;

  var = 0;

  while (var < 19)
    var++;

  result = divident / divisor; // FLAW
}
