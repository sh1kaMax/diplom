// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора

#include <stdlib.h>

int func(int param) {
  int divident = 50, result;

  int var;

  if (param > -11 && param < 15) {
    divident = 27;
  }

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = divident % param; // FLAW
    break;
  }

  return result;
}
