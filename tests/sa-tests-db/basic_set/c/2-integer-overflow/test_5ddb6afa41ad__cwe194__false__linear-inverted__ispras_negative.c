// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[42];
  short number = 41;

  strncpy(string, source_string, number);
  string[41] = '\0';

  scanf("%hd", &number);
  if (number > 41)
    number = 41;
}
