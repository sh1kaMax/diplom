// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

void func(void) {
  int divident = 36, divisor = 7, result;
  int var_a = 154;
  int var_b = 156;

  divisor = var_a - var_b;

  if (divisor == 0)
    goto error_label;

  divisor = var_a;

  exit(0);

error_label:
  result = divident / divisor;
}
