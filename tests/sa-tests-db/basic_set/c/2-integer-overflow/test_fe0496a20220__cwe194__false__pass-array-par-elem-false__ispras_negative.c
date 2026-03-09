// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[13];
  short number = 12;

  int arr[100];
  int some_var = 9;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[81] = 0;

  if (some_var) {
    scanf("%hd", &number);
    if (number > 12)
      number = 12;
  }

  if (arr[81]) {
    strncpy(string, source_string, number);
    string[12] = '\0';
  }
}
