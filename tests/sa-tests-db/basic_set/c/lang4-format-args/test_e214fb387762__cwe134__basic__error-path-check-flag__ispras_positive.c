// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(void) {
  char format[57] = "Initial format string";

  int flag = 0;

  scanf("%56s", format);

  if (strchr(format, '%') != 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  strcpy(format, safe_format);

  exit(0);

error_label:
  printf(format); // FLAW
}
