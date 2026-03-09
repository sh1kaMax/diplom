// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-modulo_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int func(int param) {
  int divident = 31, result;

  int flag = 0;

  if (param == 0) {
    divident = 74;
  }

  if (param == 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  exit(0);

error_label:
  result = divident % param; // FLAW

  return result;
}
