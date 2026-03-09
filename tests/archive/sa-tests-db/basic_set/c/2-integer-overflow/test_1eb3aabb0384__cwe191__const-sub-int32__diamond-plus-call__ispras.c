// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-int32.json
//
// Знаковое значение задается с помощью константы INT_MIN.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
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
  int32_t data = 1;
  int32_t result;

  int func_res = ret_func(10);

  if (param + func_res > 41) {
    data = INT_MIN;
  }

  if (param + func_res > 41) {
    result = data - 1; // FLAW
  }
}
