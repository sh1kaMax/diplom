// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-lower_bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только снизу
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними

#include <stdlib.h>

int func(int param) {
  int divident = 35, result;

  if (param > -10) {
    divident = 13;
  }

  param = 35;

  result = divident % param;

  return result;
}
