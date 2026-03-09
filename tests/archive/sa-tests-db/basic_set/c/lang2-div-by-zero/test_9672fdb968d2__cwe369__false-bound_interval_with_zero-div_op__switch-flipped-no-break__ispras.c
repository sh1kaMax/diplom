// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора

#include <stdlib.h>

int func(int param) {
  int divident = 43, result;

  int var;

  if (param > 15 && param < 30) {
    divident = 42;
  } else {
    return 0;
  }

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = divident / param;
    break;
  }

  return result;
}
