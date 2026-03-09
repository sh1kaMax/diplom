// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-upper_bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только сверху
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними

#include <stdlib.h>

int func(int param) {
  int divident = 44, result;

  int var;

  if (param < -19) {
    divident = 47;
  } else {
    return 0;
  }

  var = 0;

  for (var = 0; var < 10; var++)
    ;

  result = divident % param;

  return result;
}
