// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

void func(void) {
  int divident = 58, divisor = 10, result;
  int var_a = 162;
  int var_b = 162;

  int var;

  divisor = var_a - var_b;

  var = 0;

  while (var < 18)
    var++;

  result = divident / divisor; // FLAW
}
