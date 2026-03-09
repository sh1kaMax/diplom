// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdlib.h>

void func(void) {
  float divident = 48.24, divisor = 26.24, result;

  int var;

  divisor = 0.0;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    result = divident / divisor;
    break;
  }
}
