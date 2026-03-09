// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному снизу и сверху
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости

#include <stdlib.h>

int func(int param) {
  int divident = 20, result;

  if (param > -9 && param < 14) {
    divident = 78;
  }

  if (!(param == 0)) {
    exit(0);
  } else {
    result = divident % param; // FLAW
  }

  return result;
}
