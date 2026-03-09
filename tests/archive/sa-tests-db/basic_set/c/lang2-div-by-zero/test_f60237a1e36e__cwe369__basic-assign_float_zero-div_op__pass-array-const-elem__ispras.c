// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  float divident = 61.55, divisor = 19.48, result;

  int arr[100];
  arr[9] = param;
  arr[83] = 7;

  if (param) {
    divisor = 0.0;
  }

  param = arr[9];

  if (param) {
    result = divident / divisor; // FLAW
  }
}
