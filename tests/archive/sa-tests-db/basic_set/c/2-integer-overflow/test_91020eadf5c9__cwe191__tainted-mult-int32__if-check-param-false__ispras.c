// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: tainted-mult-int32.json
//
// Знаковое значение вводится с помощью функции scanf.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое может привести к переполнению снизу.
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(int param) {
  int32_t data = 1;
  int32_t result;

  scanf("%d", &data);

  if (param > 40 && param < 41) {
    result = data * 2;
  }
}
