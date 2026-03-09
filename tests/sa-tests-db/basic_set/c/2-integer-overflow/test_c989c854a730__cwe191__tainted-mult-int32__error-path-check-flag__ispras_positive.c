// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: tainted-mult-int32.json
//
// Знаковое значение вводится с помощью функции scanf.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое может привести к переполнению снизу.
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
  int32_t data = 1;
  int32_t result;

  int flag = 0;

  scanf("%d", &data);

  if (data <= INT_MIN / 2 - 1)
    flag = 1;

  if (flag != 0)
    goto error_label;

  data = 0;

  exit(0);

error_label:
  result = data * 2; // FLAW
}
