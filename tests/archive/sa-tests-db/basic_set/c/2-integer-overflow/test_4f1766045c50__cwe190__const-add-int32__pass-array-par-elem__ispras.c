// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int32.json
//
// Знаковое значение задается с помощью константы INT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  int32_t data = 0;
  int32_t result;

  int arr[100];
  int some_var = 4;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[58] = 7;

  if (some_var) {
    data = INT_MAX;
  }

  if (arr[param]) {
    result = data + 1; // FLAW
  }
}
