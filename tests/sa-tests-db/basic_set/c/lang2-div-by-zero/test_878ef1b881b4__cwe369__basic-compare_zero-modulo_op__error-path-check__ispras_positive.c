// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-modulo_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int func(int param) {
  int divident = 29, result;

  if (param == 0) {
    divident = 29;
  }

  if (param == 0)
    goto error_label;

  exit(0);

error_label:
  result = divident % param; // FLAW

  return result;
}
