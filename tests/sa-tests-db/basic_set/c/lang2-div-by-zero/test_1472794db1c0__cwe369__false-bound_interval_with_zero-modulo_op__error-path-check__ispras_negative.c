// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int func(int param) {
  int divident = 70, result;

  if (param > 8 && param < 30) {
    divident = 24;
  } else {
    return 0;
  }

  if (param == 0)
    goto error_label;

  exit(0);

error_label:
  result = divident % param;

  return result;
}
