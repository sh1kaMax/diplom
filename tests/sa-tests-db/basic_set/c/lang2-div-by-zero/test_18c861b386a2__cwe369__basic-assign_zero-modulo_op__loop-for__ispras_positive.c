// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

void func(void) {
  int divident = 66, divisor = 8, result;

  int var;

  divisor = 0;

  var = 0;

  for (var = 0; var < 14; var++)
    ;

  result = divident % divisor; // FLAW
}
