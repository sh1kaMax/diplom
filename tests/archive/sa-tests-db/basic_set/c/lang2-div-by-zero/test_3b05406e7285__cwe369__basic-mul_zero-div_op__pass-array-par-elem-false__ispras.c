// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-mul_zero-div_op.json
//
// Нулевое значение получается как результат умножения.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 69, divisor = 3, result;
  int var_a = 0;

  int arr[100];
  int some_var = 5;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[84] = 0;

  if (some_var) {
    divisor = param * var_a;
  }

  if (arr[84]) {
    result = divident / divisor;
  }
}
