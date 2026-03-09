// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

void func(void) {
  int divident = 19, divisor = 7, result;
  int var_a = 30;
  int var_b = 36;

  int var;

  divisor = var_a - var_b;

  var = 0;

  while (var < 12)
    var++;

  result = divident / divisor;
}
