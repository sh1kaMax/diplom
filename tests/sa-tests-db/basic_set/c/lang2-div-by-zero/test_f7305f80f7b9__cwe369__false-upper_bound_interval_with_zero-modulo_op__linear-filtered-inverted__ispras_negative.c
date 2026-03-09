// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-upper_bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только сверху
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: linear-filtered-inverted.c
// Прямолинейный участок кода от источника до стока с фильтрацией после стока

#include <stdlib.h>

int func(int param) {
  int divident = 24, result;

  if (param < -6) {
    divident = 43;
  } else {
    return 0;
  }

  result = divident % param;

  param = 4;

  return result;
}
