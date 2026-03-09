// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-upper_bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только сверху
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока

#include <stdlib.h>

int func(int param) {
  int divident = 38, result;

  if (param < -16) {
    divident = 54;
  } else {
    return 0;
  }

  result = divident / param;

  return result;
}
