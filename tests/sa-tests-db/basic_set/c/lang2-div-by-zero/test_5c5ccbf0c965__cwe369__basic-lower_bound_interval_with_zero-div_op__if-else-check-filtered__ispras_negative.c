// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-lower_bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только снизу
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости

#include <stdlib.h>

int func(int param) {
  int divident = 59, result;

  if (param > -11) {
    divident = 89;
  }

  if (param == 0) {
    param = 59;
  } else {
    result = divident / param;
  }

  return result;
}
