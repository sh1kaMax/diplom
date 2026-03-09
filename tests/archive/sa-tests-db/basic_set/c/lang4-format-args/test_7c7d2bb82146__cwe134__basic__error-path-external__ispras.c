// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int external_func(void);

const char safe_format[] = "Safe format string";

void func(void) {
  char format[52] = "Initial format string";

  scanf("%51s", format);

  if (external_func())
    goto error_label;

  strcpy(format, safe_format);

  exit(0);

error_label:
  printf(format); // FLAW
}
