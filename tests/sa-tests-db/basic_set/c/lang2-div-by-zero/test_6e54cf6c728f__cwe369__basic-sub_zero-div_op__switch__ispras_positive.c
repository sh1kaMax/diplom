// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

void func(void) {
  int divident = 59, divisor = 9, result;
  int var_a = 112;
  int var_b = 112;

  int var;

  divisor = var_a - var_b;

  var = 0;

  switch (var) {
  case 0:
    result = divident / divisor; // FLAW
    break;
  case 1:
    exit(0);
  }
}
