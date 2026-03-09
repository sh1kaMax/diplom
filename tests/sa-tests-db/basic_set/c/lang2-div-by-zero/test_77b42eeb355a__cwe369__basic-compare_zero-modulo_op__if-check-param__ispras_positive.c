// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-modulo_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции

#include <stdlib.h>

int func(int param, int param2) {
  int divident = 23, result;

  if (param == 0) {
    divident = 44;
  }

  if (param2 > 2) {
    result = divident % param; // FLAW
  }

  return result;
}
