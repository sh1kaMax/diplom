// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-upper_bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора выбора

#include <stdlib.h>

int func(int param) {
  int divident = 58, result;

  int var;

  if (param < 20) {
    divident = 22;
  }

  var = 0;

  switch (var) {
  default:
    result = divident / param;
    break;
  case 0:
    exit(0);
    break;
  }

  return result;
}
