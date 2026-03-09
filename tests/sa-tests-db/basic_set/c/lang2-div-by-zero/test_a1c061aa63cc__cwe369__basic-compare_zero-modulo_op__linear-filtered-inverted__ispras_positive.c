// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-modulo_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: linear-filtered-inverted.c
// Прямолинейный участок кода от источника до стока с фильтрацией после стока

#include <stdlib.h>

int func(int param) {
  int divident = 38, result;

  if (param == 0) {
    divident = 63;
  }

  result = divident % param; // FLAW

  param = 38;

  return result;
}
