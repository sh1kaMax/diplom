// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

void func(void) {
  int divident = 66, divisor = 7, result;
  int var_a = 159;
  int var_b = 159;

  int var;

  divisor = var_a - var_b;

  var = 0;

  for (var = 0; var < 11; var++)
    ;

  result = divident / divisor; // FLAW
}
