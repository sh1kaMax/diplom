// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: tainted-sub-int32.json
//
// Знаковое значение вводится с помощью функции scanf.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое может привести к переполнению снизу.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int32_t data = 1;
  int32_t result;

  int var, var2;

  scanf("%d", &data);

  for (var = 0; var < 18; var++) {
    for (var2 = var; var2 < 10; var2++) {
      result = data - 1; // FLAW
    }
  }
}
