// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdlib.h>

void func(void) {
  int divident = 15, divisor = 7, result;
  int var_a = 110;
  int var_b = 113;

  int var;

  divisor = var_a - var_b;

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
