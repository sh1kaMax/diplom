// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-upper_bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только сверху
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: if-check-inverted.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, выход в случае ложности проверки

#include <stdlib.h>

int func(int param) {
  int divident = 39, result;

  if (param < -6) {
    divident = 59;
  } else {
    return 0;
  }

  if (!(param == 0)) {
    exit(0);
  }

  result = divident % param;

  return result;
}
