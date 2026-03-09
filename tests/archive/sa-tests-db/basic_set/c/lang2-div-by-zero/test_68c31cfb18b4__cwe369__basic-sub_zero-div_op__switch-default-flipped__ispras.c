// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdlib.h>

void func(void) {
  int divident = 16, divisor = 6, result;
  int var_a = 100;
  int var_b = 100;

  int var;

  divisor = var_a - var_b;

  var = 0;

  switch (var) {
  default:
    result = divident / divisor;
    break;
  case 0:
    exit(0);
    break;
  }
}
