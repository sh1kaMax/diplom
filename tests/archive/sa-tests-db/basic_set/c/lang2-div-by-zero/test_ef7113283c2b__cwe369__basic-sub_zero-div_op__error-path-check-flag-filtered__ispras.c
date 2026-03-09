// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdlib.h>

void func(void) {
  int divident = 58, divisor = 7, result;
  int var_a = 108;
  int var_b = 108;

  int flag = 0;

  divisor = var_a - var_b;

  if (divisor == 0)
    flag = 1;

  if (flag != 0) {

    divisor = var_a;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident / divisor;
}
