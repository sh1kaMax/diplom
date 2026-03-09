// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint32.json
//
// Беззнаковое значение задается с помощью константы UINT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  uint32_t data = 0;
  uint32_t result;

  int arr[100];
  int some_var = 19;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[78] = 0;

  if (some_var) {
    data = UINT_MAX;
  }

  if (arr[78]) {
    result = data + 1;
  }
}
