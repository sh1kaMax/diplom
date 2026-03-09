// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int64.json
//
// Знаковое значение задается с помощью константы LLONG_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  int64_t data = 0;
  int64_t result;

  if (param % 2 == 0) {
    data = LLONG_MAX;
  }

  if (param % 2 == 1) {
    result = data + 1;
  }
}
