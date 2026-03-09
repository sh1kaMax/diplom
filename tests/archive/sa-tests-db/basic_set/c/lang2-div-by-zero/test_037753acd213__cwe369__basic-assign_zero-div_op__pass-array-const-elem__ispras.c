// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-div_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 32, divisor = 4, result;

  int arr[100];
  arr[18] = param;
  arr[73] = 7;

  if (param) {
    divisor = 0;
  }

  param = arr[18];

  if (param) {
    result = divident / divisor; // FLAW
  }
}
