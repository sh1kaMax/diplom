// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, выход в случае истинности проверки.

#include <stdlib.h>

void func(void) {
  int divident = 59, divisor = 6, result;
  int var_a = 153;
  int var_b = 153;

  divisor = var_a - var_b;

  if (divisor == 0) {
    exit(0);
  }

  result = divident / divisor;
}
