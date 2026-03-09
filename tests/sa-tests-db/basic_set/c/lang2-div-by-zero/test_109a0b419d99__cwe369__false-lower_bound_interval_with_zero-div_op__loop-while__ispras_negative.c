// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-lower_bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только снизу
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними

#include <stdlib.h>

int func(int param) {
  int divident = 20, result;

  int var;

  if (param > 15) {
    divident = 3;
  } else {
    return 0;
  }

  var = 0;

  while (var < 10)
    var++;

  result = divident / param;

  return result;
}
