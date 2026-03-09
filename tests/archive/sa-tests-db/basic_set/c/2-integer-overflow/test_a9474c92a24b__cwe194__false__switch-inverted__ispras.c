// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: switch-inverted.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке оператора выбора.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[53];
  short number = 52;

  int var;

  scanf("%hd", &number);
  if (number > 52)
    number = 52;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  case 1:
    strncpy(string, source_string, number);
    string[52] = '\0';
    break;
  }
}
