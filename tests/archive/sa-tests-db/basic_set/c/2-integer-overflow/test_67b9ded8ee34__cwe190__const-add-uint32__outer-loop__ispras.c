// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint32.json
//
// Беззнаковое значение задается с помощью константы UINT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int iter_var;

  uint32_t data = 0;
  uint32_t result;

  for (iter_var = 9; iter_var < 22; iter_var++) {
    data = UINT_MAX;

    result = data + 1; // FLAW
  }
}
