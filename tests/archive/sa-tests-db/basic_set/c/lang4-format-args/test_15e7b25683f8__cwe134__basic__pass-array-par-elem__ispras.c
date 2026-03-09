// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(int param) {
  char format[55] = "Initial format string";

  int arr[100];
  int some_var = 25;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[61] = 7;

  if (some_var) {
    scanf("%54s", format);
  }

  if (arr[param]) {
    printf(format); // FLAW
  }
}
