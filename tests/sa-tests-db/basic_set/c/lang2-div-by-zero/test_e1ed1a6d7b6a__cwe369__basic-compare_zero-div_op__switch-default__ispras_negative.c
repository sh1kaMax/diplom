// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-div_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора выбора

#include <stdlib.h>

int func(int param) {
  int divident = 25, result;

  int var;

  if (param == 0) {
    divident = 76;
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    result = divident / param;
    break;
  }

  return result;
}
