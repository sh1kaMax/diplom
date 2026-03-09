// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int external_func(void);

char *source_string;

void func(void) {
  char string[55];
  short number = 54;

  scanf("%hd", &number);
  if (number > 54)
    number = 54;

  if (external_func())
    goto error_label;

  number = 54;

  exit(0);

error_label:
  strncpy(string, source_string, number); // FLAW
  string[54] = '\0';
}
