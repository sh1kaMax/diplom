// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-and_zero-div_op.json
//
// Нулевое значение получается как результат побитового и.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 48, divisor = 10, result;
  int var_a = 0;

  int arr[100];
  arr[10] = !param;
  arr[76] = 7;

  if (param) {
    divisor = param & var_a;
  }

  param = arr[10];

  if (param) {
    result = divident / divisor;
  }
}
