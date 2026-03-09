// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора выбора

#include <stdlib.h>

int func(int param) {
  int divident = 46, result;

  int var;

  if (param > -12 && param < 20) {
    divident = 39;
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    result = divident / param;
    break;
  }

  return result;
}
