// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-upper_bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int func(int param) {
  int divident = 60, result;

  if (param < 13) {
    divident = 44;
  }

  if (external_func())
    goto error_label;

  param = 13;

  exit(0);

error_label:
  result = divident / param; // FLAW

  return result;
}
