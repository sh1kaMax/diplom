// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 30, divisor = 8, result;
  int var_a = 103;
  int var_b = 103;

  int arr[100];
  arr[31] = param;
  arr[85] = 7;

  if (param) {
    divisor = var_a - var_b;
  }

  param = arr[31];

  if (param) {
    result = divident / divisor; // FLAW
  }
}
