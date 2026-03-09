// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[79];
  short number = 78;

  int var;

  scanf("%hd", &number);
  if (number > 78)
    number = 78;

  var = 0;

  for (var = 0; var < 12; var++)
    ;

  strncpy(string, source_string, number); // FLAW
  string[78] = '\0';
}
