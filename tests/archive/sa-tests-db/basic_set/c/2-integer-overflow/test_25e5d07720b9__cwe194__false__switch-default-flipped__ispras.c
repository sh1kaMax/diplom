// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: switch-default-flipped.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[15];
  short number = 14;

  int var;

  scanf("%hd", &number);
  if (number > 14)
    number = 14;

  var = 0;

  switch (var) {
  default:
    strncpy(string, source_string, number);
    string[14] = '\0';
    break;
  case 0:
    exit(0);
    break;
  }
}
