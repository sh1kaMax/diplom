// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

void func(void) {
  float divident = 19.74, divisor = 29.71, result;

  int var;

  divisor = 0.0;

  var = 0;

  switch (var) {
  case 1:
    result = divident / divisor;
    break;
  case 0:
    exit(0);
    break;
  }
}
