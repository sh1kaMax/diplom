// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-upper_bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check-inverted-filtered.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости

#include <stdlib.h>

int func(int param) {
  int divident = 32, result;

  if (param < 16) {
    divident = 80;
  }

  if (!(param == 0)) {
    param = 16;
  } else {
    result = divident / param; // FLAW
  }

  return result;
}
