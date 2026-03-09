// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint32.json
//
// Беззнаковое значение задается с помощью константы UINT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(void) {
  uint32_t data = 0;
  uint32_t result;

  int flag = 0;

  data = UINT_MAX;

  if (data >= UINT_MAX)
    flag = 1;

  if (flag != 0)
    goto error_label;

  data = 0;

  exit(0);

error_label:
  result = data + 1; // FLAW
}
