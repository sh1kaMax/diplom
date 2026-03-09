// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int external_func(void);

const char safe_format[] = "Safe format string";

void func(void) {
  char format[59] = "Initial format string";

  scanf("%58s", format);

  if (external_func()) {

    strcpy(format, safe_format);

    goto error_label;
  }

  exit(0);

error_label:
  printf(format);
}
