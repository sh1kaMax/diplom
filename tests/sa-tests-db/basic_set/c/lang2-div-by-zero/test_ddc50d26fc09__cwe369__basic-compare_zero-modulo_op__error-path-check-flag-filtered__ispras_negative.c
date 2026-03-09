// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-modulo_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: error-path-check-flag-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки, фильтрация и последующий
// переход по метке со стоком.

#include <stdlib.h>

int func(int param) {
  int divident = 28, result;

  int flag = 0;

  if (param == 0) {
    divident = 49;
  }

  if (param == 0)
    flag = 1;

  if (flag != 0) {

    param = 28;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident % param;

  return result;
}
