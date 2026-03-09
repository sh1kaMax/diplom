// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-lower_bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только снизу
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора выбора

#include <stdlib.h>

int func(int param) {
  int divident = 47, result;

  int var;

  if (param > -15) {
    divident = 75;
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    result = divident % param;
    break;
  }

  return result;
}
