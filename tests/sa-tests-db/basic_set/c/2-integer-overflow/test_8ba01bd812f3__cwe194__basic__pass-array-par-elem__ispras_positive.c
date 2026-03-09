// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[69];
  short number = 68;

  int arr[100];
  int some_var = 0;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[98] = 7;

  if (some_var) {
    scanf("%hd", &number);
    if (number > 68)
      number = 68;
  }

  if (arr[param]) {
    strncpy(string, source_string, number); // FLAW
    string[68] = '\0';
  }
}
