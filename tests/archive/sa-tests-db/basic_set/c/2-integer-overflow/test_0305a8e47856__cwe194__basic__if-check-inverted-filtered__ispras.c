// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[97];
  short number = 96;

  scanf("%hd", &number);
  if (number > 96)
    number = 96;

  if (!(number < 0)) {
    number = 96;
  }

  strncpy(string, source_string, number); // FLAW
  string[96] = '\0';
}
