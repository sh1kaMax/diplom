// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdlib.h>

void func(void) {
  float divident = 48.23, divisor = 24.19, result;

  divisor = 0.0;

  if (divisor == 0.0) {

    divisor = 65.68;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident / divisor;
}
