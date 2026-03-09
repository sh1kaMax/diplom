// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: switch-default-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(void) {
  char format[80] = "Initial format string";

  int var;

  scanf("%79s", format);

  var = 0;

  switch (var) {
  default:
    printf(format);
    break;
  case 0:
    exit(0);
    break;
  }
}
