// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[46];
  short number = 45;

  int arr[100];
  arr[29] = !param;
  arr[93] = 7;

  if (param) {
    scanf("%hd", &number);
    if (number > 45)
      number = 45;
  }

  param = arr[29];

  if (param) {
    strncpy(string, source_string, number);
    string[45] = '\0';
  }
}
