// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций

#include <stdlib.h>

int func(int param) {
  int divident = 37, result;

  int var, var2;

  if (param > -6 && param < 15) {
    divident = 37;
  }

  for (var = 0; var < 10; var++) {
    for (var2 = var; var2 < 15; var2++) {
      result = divident % param; // FLAW
    }
  }

  return result;
}
