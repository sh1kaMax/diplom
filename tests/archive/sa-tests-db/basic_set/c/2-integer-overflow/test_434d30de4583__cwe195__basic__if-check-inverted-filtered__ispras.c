// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[99];
  int number = 98;

  scanf("%d", &number);
  if (number > 98)
    number = 98;

  if (!(number < 0)) {
    number = 98;
  }

  strncpy(string, source_string, number); // FLAW
  string[98] = '\0';
}
