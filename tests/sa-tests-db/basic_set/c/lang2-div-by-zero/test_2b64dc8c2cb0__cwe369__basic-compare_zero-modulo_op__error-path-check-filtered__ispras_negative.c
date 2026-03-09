// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-modulo_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: error-path-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация и переход по метке в случае истинности проверки.

#include <stdlib.h>

int func(int param) {
  int divident = 57, result;

  if (param == 0) {
    divident = 37;
  }

  if (param == 0) {

    param = 57;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident % param;

  return result;
}
