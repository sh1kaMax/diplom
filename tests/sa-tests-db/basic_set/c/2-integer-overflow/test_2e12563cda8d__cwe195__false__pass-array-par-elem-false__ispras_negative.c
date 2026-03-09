// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[58];
  int number = 57;

  int arr[100];
  int some_var = 48;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[82] = 0;

  if (some_var) {
    scanf("%d", &number);
    if (number > 57)
      number = 57;
  }

  if (arr[82]) {
    strncpy(string, source_string, number);
    string[57] = '\0';
  }
}
