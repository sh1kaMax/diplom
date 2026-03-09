// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(void) {
  char format[55] = "Initial format string";

  scanf("%54s", format);

  if (strchr(format, '%') != 0) {

    strcpy(format, safe_format);

    goto error_label;
  }

  exit(0);

error_label:
  printf(format);
}
