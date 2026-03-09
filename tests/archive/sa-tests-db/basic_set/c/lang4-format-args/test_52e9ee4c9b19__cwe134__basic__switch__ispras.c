// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void func(void) {
  char format[70] = "Initial format string";

  int var;

  scanf("%69s", format);

  var = 0;

  switch (var) {
  case 0:
    printf(format); // FLAW
    break;
  case 1:
    exit(0);
  }
}
