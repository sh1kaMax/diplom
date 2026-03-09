// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-modulo_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки

#include <stdlib.h>

int func(int param) {
  int divident = 30, result;

  if (param == 0) {
    divident = 86;
  }

  if (param == 0) {
    param = 30;
  }

  result = divident % param;

  return result;
}
