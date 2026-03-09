// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(int param) {
  char format[45] = "Initial format string";

  if (param % 2 == 0) {
    scanf("%44s", format);
  }

  if (param % 2 == 1) {
    printf(format);
  }
}
