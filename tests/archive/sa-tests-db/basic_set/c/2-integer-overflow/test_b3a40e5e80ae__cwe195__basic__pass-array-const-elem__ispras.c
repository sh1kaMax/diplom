// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[31];
  int number = 30;

  int arr[100];
  arr[13] = param;
  arr[91] = 7;

  if (param) {
    scanf("%d", &number);
    if (number > 30)
      number = 30;
  }

  param = arr[13];

  if (param) {
    strncpy(string, source_string, number); // FLAW
    string[30] = '\0';
  }
}
