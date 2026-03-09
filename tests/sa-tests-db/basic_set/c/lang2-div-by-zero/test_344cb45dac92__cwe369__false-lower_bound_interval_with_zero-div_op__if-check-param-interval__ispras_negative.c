// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-lower_bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только снизу
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции

#include <stdlib.h>

int func(int param, int param2) {
  int divident = 45, result;

  if (param > 18) {
    divident = 38;
  } else {
    return 0;
  }

  if (param2 > 50 && param2 < 62) {
    result = divident / param;
  }

  return result;
}
