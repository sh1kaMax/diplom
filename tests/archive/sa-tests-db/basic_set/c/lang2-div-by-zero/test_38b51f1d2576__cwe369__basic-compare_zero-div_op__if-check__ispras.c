// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-div_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, выход в случае истинности проверки

#include <stdlib.h>

int func(int param) {
  int divident = 47, result;

  if (param == 0) {
    divident = 82;
  }

  if (param == 0) {
    exit(0);
  }

  result = divident / param;

  return result;
}
