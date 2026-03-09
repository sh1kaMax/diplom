// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[23];
  short number = 22;

  scanf("%hd", &number);
  if (number > 22)
    number = 22;

  if (number < 0)
    goto error_label;

  number = 22;

  exit(0);

error_label:
  strncpy(string, source_string, number); // FLAW
  string[22] = '\0';
}
