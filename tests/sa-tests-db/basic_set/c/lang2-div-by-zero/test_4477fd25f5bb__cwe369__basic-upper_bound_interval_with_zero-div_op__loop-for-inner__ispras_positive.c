// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-upper_bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций

#include <stdlib.h>

int func(int param) {
  int divident = 25, result;

  int var, var2;

  if (param < 5) {
    divident = 35;
  }

  for (var = 0; var < 10; var++) {
    for (var2 = var; var2 < 15; var2++) {
      result = divident / param; // FLAW
    }
  }

  return result;
}
