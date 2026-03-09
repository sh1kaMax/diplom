// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-uint32.json
//
// Беззнаковое значение задается с помощью константы 0.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  uint32_t data = 1;
  uint32_t result;

  int arr[100];
  int some_var = 8;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[62] = 0;

  if (some_var) {
    data = 0;
  }

  if (arr[62]) {
    result = data - 1;
  }
}
