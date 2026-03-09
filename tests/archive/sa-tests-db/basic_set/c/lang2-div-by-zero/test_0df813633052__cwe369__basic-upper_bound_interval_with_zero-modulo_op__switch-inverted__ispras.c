// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-upper_bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора

#include <stdlib.h>

int func(int param) {
  int divident = 61, result;

  int var;

  if (param < 8) {
    divident = 18;
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  case 1:
    result = divident % param;
    break;
  }

  return result;
}
