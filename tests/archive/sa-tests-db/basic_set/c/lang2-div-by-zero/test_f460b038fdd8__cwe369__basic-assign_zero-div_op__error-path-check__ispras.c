// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-div_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

void func(void) {
  int divident = 66, divisor = 5, result;

  divisor = 0;

  if (divisor == 0)
    goto error_label;

  divisor = 5;

  exit(0);

error_label:
  result = divident / divisor; // FLAW
}
