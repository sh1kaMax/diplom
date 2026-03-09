// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-div_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

void func(void) {
  int divident = 41, divisor = 7, result;

  int var;

  divisor = 0;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  case 1:
    result = divident / divisor;
    break;
  }
}
