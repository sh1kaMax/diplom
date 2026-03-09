// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-lower_bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только снизу
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока

#include <stdlib.h>

int func(int param) {
  int divident = 58, result;

  if (param > -5) {
    divident = 48;
  }

  result = divident % param; // FLAW

  return result;
}
