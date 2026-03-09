// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

void func(void) {
  int divident = 32, divisor = 4, result;
  int var_a = 108;
  int var_b = 114;

  int var;

  divisor = var_a - var_b;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = divident / divisor;
    break;
  }
}
