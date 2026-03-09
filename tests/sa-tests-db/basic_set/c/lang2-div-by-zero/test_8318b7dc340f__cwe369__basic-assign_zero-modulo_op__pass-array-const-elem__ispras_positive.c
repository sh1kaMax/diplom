// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 42, divisor = 3, result;

  int arr[100];
  arr[50] = param;
  arr[91] = 7;

  if (param) {
    divisor = 0;
  }

  param = arr[50];

  if (param) {
    result = divident % divisor; // FLAW
  }
}
