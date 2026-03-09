// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

void func(void) {
  int divident = 36, divisor = 9, result;
  int var_a = 65;
  int var_b = 65;

  divisor = var_a - var_b;

  if (divisor == 0)
    goto error_label;

  divisor = var_a;

  exit(0);

error_label:
  result = divident / divisor; // FLAW
}
