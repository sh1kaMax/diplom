// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 51, divisor = 6, result;
  int var_a = 127;
  int var_b = 132;

  int arr[100];
  arr[48] = !param;
  arr[92] = 7;

  if (param) {
    divisor = var_a - var_b;
  }

  param = arr[48];

  if (param) {
    result = divident / divisor;
  }
}
