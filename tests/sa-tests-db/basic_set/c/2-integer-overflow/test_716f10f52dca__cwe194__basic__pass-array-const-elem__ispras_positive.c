// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[70];
  short number = 69;

  int arr[100];
  arr[49] = param;
  arr[60] = 7;

  if (param) {
    scanf("%hd", &number);
    if (number > 69)
      number = 69;
  }

  param = arr[49];

  if (param) {
    strncpy(string, source_string, number); // FLAW
    string[69] = '\0';
  }
}
