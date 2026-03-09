// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: switch-default-inverted.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[13];
  short number = 12;

  int var;

  scanf("%hd", &number);
  if (number > 12)
    number = 12;

  var = 0;

  switch (var) {
  case 0:
    strncpy(string, source_string, number); // FLAW
    string[12] = '\0';
    break;
  default:
    exit(0);
    break;
  }
}
