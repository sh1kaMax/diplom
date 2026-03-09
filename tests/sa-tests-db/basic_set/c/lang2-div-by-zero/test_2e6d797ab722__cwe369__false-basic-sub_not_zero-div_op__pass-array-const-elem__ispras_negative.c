// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 68, divisor = 7, result;
  int var_a = 20;
  int var_b = 21;

  int arr[100];
  arr[46] = param;
  arr[53] = 7;

  if (param) {
    divisor = var_a - var_b;
  }

  param = arr[46];

  if (param) {
    result = divident / divisor;
  }
}
