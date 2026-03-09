// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[31];
  short number = 30;

  if (param & 0x1D) {
    scanf("%hd", &number);
    if (number > 30)
      number = 30;
  }

  if (param & 0x1D) {
    strncpy(string, source_string, number); // FLAW
    string[30] = '\0';
  }
}
