// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default-inverted.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

void func(void) {
  int divident = 15, divisor = 6, result;
  int var_a = 15;
  int var_b = 15;

  int var;

  divisor = var_a - var_b;

  var = 0;

  switch (var) {
  case 0:
    result = divident / divisor; // FLAW
    break;
  default:
    exit(0);
    break;
  }
}
