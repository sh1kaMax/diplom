// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

int ret_func(int param1) { return param1; }

void func(int param) {
  char format[30] = "Initial format string";

  int func_res = ret_func(10);

  if (param + func_res > 42) {
    scanf("%29s", format);
  }

  if (param + func_res < 42) {
    printf(format);
  }
}
