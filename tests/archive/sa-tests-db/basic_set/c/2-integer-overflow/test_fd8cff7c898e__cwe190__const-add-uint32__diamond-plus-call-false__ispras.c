// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint32.json
//
// Беззнаковое значение задается с помощью константы UINT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int ret_func(int param1) { return param1; }

void func(int param) {
  uint32_t data = 0;
  uint32_t result;

  int func_res = ret_func(10);

  if (param + func_res > 31) {
    data = UINT_MAX;
  }

  if (param + func_res < 31) {
    result = data + 1;
  }
}
