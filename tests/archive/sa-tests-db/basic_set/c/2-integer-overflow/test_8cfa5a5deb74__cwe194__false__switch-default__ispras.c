// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[67];
  short number = 66;

  int var;

  scanf("%hd", &number);
  if (number > 66)
    number = 66;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    strncpy(string, source_string, number);
    string[66] = '\0';
    break;
  }
}
