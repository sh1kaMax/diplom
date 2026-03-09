// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация и переход по метке в случае истинности проверки.

#include <stdlib.h>

int func(int param) {
  int divident = 17, result;

  if (param > -20 && param < 7) {
    divident = 13;
  }

  if (param == 0) {

    param = 7;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident / param;

  return result;
}
