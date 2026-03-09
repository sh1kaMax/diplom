// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-uint32.json
//
// Беззнаковое значение задается с помощью константы 0.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
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
  uint32_t data = 1;
  uint32_t result;

  data = 0;

  if (external_func()) {

    data = 1;

    goto error_label;
  }

  exit(0);

error_label:
  result = data - 1;
}
