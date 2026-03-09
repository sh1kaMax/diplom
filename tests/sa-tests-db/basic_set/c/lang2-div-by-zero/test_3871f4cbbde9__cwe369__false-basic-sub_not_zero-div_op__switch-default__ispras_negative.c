// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdlib.h>

void func(void) {
  int divident = 44, divisor = 5, result;
  int var_a = 141;
  int var_b = 146;

  int var;

  divisor = var_a - var_b;

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
