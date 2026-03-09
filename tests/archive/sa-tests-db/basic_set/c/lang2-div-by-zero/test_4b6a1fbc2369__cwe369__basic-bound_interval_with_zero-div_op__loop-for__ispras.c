// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними

#include <stdlib.h>

int func(int param) {
  int divident = 38, result;

  int var;

  if (param > -9 && param < 16) {
    divident = 36;
  }

  var = 0;

  for (var = 0; var < 10; var++)
    ;

  result = divident / param; // FLAW

  return result;
}
