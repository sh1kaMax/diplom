// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[58];
  int number = 57;

  int flag = 0;

  scanf("%d", &number);
  if (number > 57)
    number = 57;

  if (number < 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  number = 57;

  exit(0);

error_label:
  strncpy(string, source_string, number); // FLAW
  string[57] = '\0';
}
