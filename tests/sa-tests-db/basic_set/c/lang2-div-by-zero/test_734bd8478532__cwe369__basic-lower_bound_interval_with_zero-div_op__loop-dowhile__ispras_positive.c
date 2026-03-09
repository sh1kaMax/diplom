// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-lower_bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только снизу
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними

#include <stdlib.h>

int func(int param) {
  int divident = 19, result;

  int var;

  if (param > -14) {
    divident = 14;
  }

  var = 0;

  do {
    var++;
  } while (var < 10);

  result = divident / param; // FLAW

  return result;
}
