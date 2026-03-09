// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[85];
  short number = 84;

  int var;

  scanf("%hd", &number);
  if (number > 84)
    number = 84;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    strncpy(string, source_string, number); // FLAW
    string[84] = '\0';
    break;
  }
}
