// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-default-inverted.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора

#include <stdlib.h>

int func(int param) {
  int divident = 27, result;

  int var;

  if (param > 18 && param < 21) {
    divident = 51;
  } else {
    return 0;
  }

  var = 0;

  switch (var) {
  case 0:
    result = divident / param;
    break;
  default:
    exit(0);
    break;
  }

  return result;
}
