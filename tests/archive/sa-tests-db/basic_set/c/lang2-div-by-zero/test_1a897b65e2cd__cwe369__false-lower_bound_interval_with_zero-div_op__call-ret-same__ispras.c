// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-lower_bound_interval_with_zero-div_op.json
//
// Значение параметра проверяется на принадлежность ограниченному только снизу
// интервалу, не содержащему нулевое значение. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: call-ret-same.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которая просто возвращает свой аргумент. Поэтому проверка в
// вызывающей функции неуспешна и выполнение достигает стока

#include <stdlib.h>

int callee(int par1) { return par1; }

int func(int param) {
  int divident = 37, result;

  int local_res = callee(param);

  if (param > 7) {
    divident = 34;
  } else {
    return 0;
  }

  if (local_res != param) {
    exit(0);
  }

  result = divident / param;

  return result;
}
