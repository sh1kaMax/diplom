// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-uint64.json
//
// Беззнаковое значение задается с помощью константы 0.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(void) {
  uint64_t data = 1;
  uint64_t result;

  result = data - 1;

  data = 0;
}
