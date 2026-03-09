// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[49];
  short number = 48;

  int flag = 0;

  scanf("%hd", &number);
  if (number > 48)
    number = 48;

  if (number < 0)
    flag = 1;

  if (flag != 0) {

    number = 48;

    goto error_label;
  }

  exit(0);

error_label:
  strncpy(string, source_string, number);
  string[48] = '\0';
}
