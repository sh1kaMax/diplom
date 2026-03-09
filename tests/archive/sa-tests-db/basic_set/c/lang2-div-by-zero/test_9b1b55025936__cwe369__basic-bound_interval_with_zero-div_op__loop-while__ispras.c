// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними

#include <stdlib.h>

int func(int param) {
  int divident = 34, result;

  int var;

  if (param > -11 && param < 6) {
    divident = 94;
  }

  var = 0;

  while (var < 10)
    var++;

  result = divident / param; // FLAW

  return result;
}
