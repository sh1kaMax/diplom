// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(void) {
  char format[56] = "Initial format string";

  scanf("%55s", format);

  printf(format); // FLAW
}
