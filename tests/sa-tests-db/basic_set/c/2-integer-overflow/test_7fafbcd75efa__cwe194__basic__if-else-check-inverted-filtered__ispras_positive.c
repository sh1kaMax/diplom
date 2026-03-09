// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: if-else-check-inverted-filtered.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[75];
  short number = 74;

  scanf("%hd", &number);
  if (number > 74)
    number = 74;

  if (!(number < 0)) {
    number = 74;
  } else {
    strncpy(string, source_string, number); // FLAW
    string[74] = '\0';
  }
}
