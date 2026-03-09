// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(void) {
  char format[33] = "Initial format string";

  int var, var2;

  scanf("%32s", format);

  for (var = 0; var < 16; var++) {
    for (var2 = var; var2 < 12; var2++) {
      printf(format); // FLAW
    }
  }
}
