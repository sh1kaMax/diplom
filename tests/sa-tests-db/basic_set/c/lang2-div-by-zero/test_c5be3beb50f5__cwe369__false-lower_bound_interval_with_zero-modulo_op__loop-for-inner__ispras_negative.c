// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-lower_bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только снизу
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций

#include <stdlib.h>

int func(int param) {
  int divident = 51, result;

  int var, var2;

  if (param > 14) {
    divident = 93;
  } else {
    return 0;
  }

  for (var = 0; var < 10; var++) {
    for (var2 = var; var2 < 15; var2++) {
      result = divident % param;
    }
  }

  return result;
}
