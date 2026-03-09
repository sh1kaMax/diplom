// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции

#include <stdlib.h>

int func(int param, int param2) {
  int divident = 23, result;

  if (param > -19 && param < 12) {
    divident = 2;
  }

  if (param2 > 19 && param2 < 39) {
    result = divident / param; // FLAW
  }

  return result;
}
