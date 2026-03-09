// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-div_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними

#include <stdlib.h>

int func(int param) {
  int divident = 27, result;

  int var;

  if (param == 0) {
    divident = 77;
  }

  var = 0;

  for (var = 0; var < 10; var++)
    ;

  result = divident / param; // FLAW

  return result;
}
