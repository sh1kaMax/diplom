// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(void) {
  int iter_var;

  char format[66] = "Initial format string";

  for (iter_var = 5; iter_var < 27; iter_var++) {
    scanf("%65s", format);

    printf(format); // FLAW
  }
}
