// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 16, divisor = 3, result;
  int var_a = 148;
  int var_b = 148;

  int arr[100];
  int some_var = 25;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[87] = 7;

  if (some_var) {
    divisor = var_a - var_b;
  }

  if (arr[param]) {
    result = divident / divisor; // FLAW
  }
}
