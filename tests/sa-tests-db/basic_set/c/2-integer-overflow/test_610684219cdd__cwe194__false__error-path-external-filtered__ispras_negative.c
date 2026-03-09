// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int external_func(void);

char *source_string;

void func(void) {
  char string[91];
  short number = 90;

  scanf("%hd", &number);
  if (number > 90)
    number = 90;

  if (external_func()) {

    number = 90;

    goto error_label;
  }

  exit(0);

error_label:
  strncpy(string, source_string, number);
  string[90] = '\0';
}
