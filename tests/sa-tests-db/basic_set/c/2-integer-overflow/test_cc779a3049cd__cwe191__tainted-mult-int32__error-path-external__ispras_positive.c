// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: tainted-mult-int32.json
//
// Знаковое значение вводится с помощью функции scanf.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое может привести к переполнению снизу.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int external_func(void);

void func(void) {
  int32_t data = 1;
  int32_t result;

  scanf("%d", &data);

  if (external_func())
    goto error_label;

  data = 0;

  exit(0);

error_label:
  result = data * 2; // FLAW
}
