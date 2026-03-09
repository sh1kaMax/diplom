// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

void func(void) {
  int divident = 27, divisor = 6, result;
  int var_a = 38;
  int var_b = 46;

  divisor = var_a - var_b;

  if (divisor == 0) {

    divisor = var_a;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident / divisor;
}
