// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: tainted-mult-int32.json
//
// Знаковое значение вводится с помощью функции scanf.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое может привести к переполнению снизу.
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
  int32_t data = 1;
  int32_t result;

  int func_res = ret_func(10);

  if (param + func_res > 11) {
    scanf("%d", &data);
  }

  if (param + func_res < 11) {
    result = data * 2;
  }
}
