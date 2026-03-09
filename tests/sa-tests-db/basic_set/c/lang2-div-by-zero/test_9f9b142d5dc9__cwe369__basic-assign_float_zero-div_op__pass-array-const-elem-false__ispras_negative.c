// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  float divident = 31.34, divisor = 26.71, result;

  int arr[100];
  arr[6] = !param;
  arr[94] = 7;

  if (param) {
    divisor = 0.0;
  }

  param = arr[6];

  if (param) {
    result = divident / divisor;
  }
}
