// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

int func(int param) {
  int divident = 42, result;

  int flag = 0;

  if (param > -14 && param < 19) {
    divident = 45;
  }

  if (param == 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  exit(0);

error_label:
  result = divident / param; // FLAW

  return result;
}
