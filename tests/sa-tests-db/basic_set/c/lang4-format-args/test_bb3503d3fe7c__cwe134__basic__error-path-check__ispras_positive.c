// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(void) {
  char format[66] = "Initial format string";

  scanf("%65s", format);

  if (strchr(format, '%') != 0)
    goto error_label;

  strcpy(format, safe_format);

  exit(0);

error_label:
  printf(format); // FLAW
}
