// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки

#include <stdlib.h>

int func(int param) {
  int divident = 48, result;

  if (param > -19 && param < 17) {
    divident = 30;
  }

  if (!(param == 0)) {
    param = 48;
  }

  result = divident % param; // FLAW

  return result;
}
