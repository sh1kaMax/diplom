// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[95];
  short number = 94;

  if (param % 2 == 0) {
    scanf("%hd", &number);
    if (number > 94)
      number = 94;
  }

  if (param % 2 == 1) {
    strncpy(string, source_string, number);
    string[94] = '\0';
  }
}
