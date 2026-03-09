// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(int param) {
  char format[67] = "Initial format string";

  int arr[100];
  arr[9] = !param;
  arr[98] = 7;

  if (param) {
    scanf("%66s", format);
  }

  param = arr[9];

  if (param) {
    printf(format);
  }
}
