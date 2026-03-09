// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником

#include <stdlib.h>

int func(int param) {
  int divident = 34, result;

  param = 4;

  if (param > 16 && param < 22) {
    divident = 77;
  } else {
    return 0;
  }

  result = divident / param;

  return result;
}
