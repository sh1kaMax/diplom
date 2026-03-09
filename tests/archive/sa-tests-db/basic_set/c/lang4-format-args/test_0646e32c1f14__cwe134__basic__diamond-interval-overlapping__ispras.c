// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(int param) {
  char format[41] = "Initial format string";

  if (param > 27 && param < 77) {
    scanf("%40s", format);
  }

  if (param > 66 && param < 74) {
    printf(format); // FLAW
  }
}
