// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

void func(void) {
  int divident = 21, divisor = 5, result;
  int var_a = 48;
  int var_b = 48;

  divisor = var_a - var_b;

  if (divisor == 0) {

    divisor = var_a;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident / divisor;
}
