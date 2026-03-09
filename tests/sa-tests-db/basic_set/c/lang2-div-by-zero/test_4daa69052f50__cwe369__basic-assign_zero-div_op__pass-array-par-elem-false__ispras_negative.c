// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-div_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 24, divisor = 3, result;

  int arr[100];
  int some_var = 33;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[73] = 0;

  if (some_var) {
    divisor = 0;
  }

  if (arr[73]) {
    result = divident / divisor;
  }
}
