// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-int64.json
//
// Знаковое значение задается с помощью константы LLONG_MIN.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int iter_var;

  int64_t data = 1;
  int64_t result;

  for (iter_var = 3; iter_var < 17; iter_var++) {
    data = LLONG_MIN;

    result = data - 1; // FLAW
  }
}
