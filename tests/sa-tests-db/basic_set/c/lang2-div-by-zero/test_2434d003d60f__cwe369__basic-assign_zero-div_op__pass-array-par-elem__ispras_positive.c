// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-div_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

void func(int param) {
  int divident = 45, divisor = 7, result;

  int arr[100];
  int some_var = 6;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[88] = 7;

  if (some_var) {
    divisor = 0;
  }

  if (arr[param]) {
    result = divident / divisor; // FLAW
  }
}
