// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 37, divisor = 5, result;
  int var_a = 71;
  int var_b = 72;

  int arr[100];
  int some_var = 3;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[79] = 0;

  if (some_var) {
    divisor = var_a - var_b;
  }

  if (arr[79]) {
    result = divident / divisor;
  }
}
