// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default-inverted.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

void func(void) {
  int divident = 29, divisor = 10, result;
  int var_a = 91;
  int var_b = 98;

  int var;

  divisor = var_a - var_b;

  var = 0;

  switch (var) {
  case 0:
    result = divident / divisor;
    break;
  default:
    exit(0);
    break;
  }
}
