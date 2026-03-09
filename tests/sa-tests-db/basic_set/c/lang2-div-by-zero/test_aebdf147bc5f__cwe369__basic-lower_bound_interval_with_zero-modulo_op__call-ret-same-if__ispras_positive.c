// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-lower_bound_interval_with_zero-modulo_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только снизу
// интервалу, содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции взятия остатка от деления).
//
// Поточный вариант: call-ret-same-if.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая возвращает свой аргумент, в зависимости от другого
// параметра. Проверка в вызывающей функции неуспешна и выполнение достигает
// стока

#include <stdlib.h>

int callee(int par1, int par2) {
  if (par2 <= 10)
    return par1;

  return 10;
}

int func(int param) {
  int divident = 62, result;

  int local_res = callee(param, 20);

  if (param > -9) {
    divident = 64;
  }

  if (local_res != 10) {
    exit(0);
  }

  result = divident % param; // FLAW

  return result;
}
