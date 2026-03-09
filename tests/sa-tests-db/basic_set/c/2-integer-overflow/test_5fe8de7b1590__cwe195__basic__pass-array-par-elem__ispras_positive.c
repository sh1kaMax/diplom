// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[70];
  int number = 69;

  int arr[100];
  int some_var = 49;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[52] = 7;

  if (some_var) {
    scanf("%d", &number);
    if (number > 69)
      number = 69;
  }

  if (arr[param]) {
    strncpy(string, source_string, number); // FLAW
    string[69] = '\0';
  }
}
