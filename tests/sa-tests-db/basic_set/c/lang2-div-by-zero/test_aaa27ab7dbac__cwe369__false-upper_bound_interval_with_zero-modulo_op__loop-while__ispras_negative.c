// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-upper_bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только сверху
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними

#include <stdlib.h>

int func(int param) {
  int divident = 52, result;

  int var;

  if (param < -12) {
    divident = 22;
  } else {
    return 0;
  }

  var = 0;

  while (var < 10)
    var++;

  result = divident % param;

  return result;
}
