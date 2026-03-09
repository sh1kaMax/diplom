// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 59, divisor = 3, result;
  int var_a = 169;
  int var_b = 169;

  int arr[100];
  arr[39] = !param;
  arr[75] = 7;

  if (param) {
    divisor = var_a - var_b;
  }

  param = arr[39];

  if (param) {
    result = divident / divisor;
  }
}
