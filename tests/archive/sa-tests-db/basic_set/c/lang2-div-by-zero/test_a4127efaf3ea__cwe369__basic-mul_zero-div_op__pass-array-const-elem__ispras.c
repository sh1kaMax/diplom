// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-mul_zero-div_op.json
//
// Нулевое значение получается как результат умножения.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 25, divisor = 4, result;
  int var_a = 0;

  int arr[100];
  arr[31] = param;
  arr[71] = 7;

  if (param) {
    divisor = param * var_a;
  }

  param = arr[31];

  if (param) {
    result = divident / divisor; // FLAW
  }
}
