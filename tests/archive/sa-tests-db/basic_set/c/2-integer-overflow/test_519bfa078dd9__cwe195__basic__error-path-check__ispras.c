// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[49];
  int number = 48;

  scanf("%d", &number);
  if (number > 48)
    number = 48;

  if (number < 0)
    goto error_label;

  number = 48;

  exit(0);

error_label:
  strncpy(string, source_string, number); // FLAW
  string[48] = '\0';
}
