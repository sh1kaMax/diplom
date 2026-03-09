// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[96];
  short number = 95;

  int flag = 0;

  scanf("%hd", &number);
  if (number > 95)
    number = 95;

  if (number < 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  number = 95;

  exit(0);

error_label:
  strncpy(string, source_string, number); // FLAW
  string[95] = '\0';
}
