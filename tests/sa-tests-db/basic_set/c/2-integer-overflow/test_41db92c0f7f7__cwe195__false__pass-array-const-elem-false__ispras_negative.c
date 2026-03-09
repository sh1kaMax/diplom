// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[69];
  int number = 68;

  int arr[100];
  arr[49] = !param;
  arr[60] = 7;

  if (param) {
    scanf("%d", &number);
    if (number > 68)
      number = 68;
  }

  param = arr[49];

  if (param) {
    strncpy(string, source_string, number);
    string[68] = '\0';
  }
}
