// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int32.json
//
// Знаковое значение задается с помощью константы INT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int32_t data = 0;
  int32_t result;

  data = 0;

  data = INT_MAX;

  result = data + 1; // FLAW
}
