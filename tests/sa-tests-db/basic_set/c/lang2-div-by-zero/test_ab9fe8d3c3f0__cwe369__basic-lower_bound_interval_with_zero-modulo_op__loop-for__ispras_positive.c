// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-lower_bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только снизу
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними

#include <stdlib.h>

int func(int param) {
  int divident = 24, result;

  int var;

  if (param > -10) {
    divident = 57;
  }

  var = 0;

  for (var = 0; var < 10; var++)
    ;

  result = divident % param; // FLAW

  return result;
}
