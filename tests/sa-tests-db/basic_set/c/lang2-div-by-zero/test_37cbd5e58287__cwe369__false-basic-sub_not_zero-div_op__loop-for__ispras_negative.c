// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

void func(void) {
  int divident = 69, divisor = 10, result;
  int var_a = 120;
  int var_b = 121;

  int var;

  divisor = var_a - var_b;

  var = 0;

  for (var = 0; var < 13; var++)
    ;

  result = divident / divisor;
}
