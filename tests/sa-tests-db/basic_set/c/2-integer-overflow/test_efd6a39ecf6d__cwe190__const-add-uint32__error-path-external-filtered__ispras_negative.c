// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint32.json
//
// Беззнаковое значение задается с помощью константы UINT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int external_func(void);

void func(void) {
  uint32_t data = 0;
  uint32_t result;

  data = UINT_MAX;

  if (external_func()) {

    data = 0;

    goto error_label;
  }

  exit(0);

error_label:
  result = data + 1;
}
