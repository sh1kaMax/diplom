// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(void) {
  char format[44] = "Initial format string";

  int var;

  scanf("%43s", format);

  var = 0;

  while (var < 19)
    var++;

  printf(format); // FLAW
}
