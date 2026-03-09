// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 55, divisor = 10, result;

  int arr[100];
  arr[16] = !param;
  arr[72] = 7;

  if (param) {
    divisor = 0;
  }

  param = arr[16];

  if (param) {
    result = divident % divisor;
  }
}
