// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint64.json
//
// Беззнаковое значение задается с помощью константы ULLONG_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int ret_func(int param1) { return param1; }

void func(int param) {
  uint64_t data = 0;
  uint64_t result;

  int func_res = ret_func(10);

  if (param + func_res > 6) {
    data = ULLONG_MAX;
  }

  if (param + func_res > 6) {
    result = data + 1; // FLAW
  }
}
