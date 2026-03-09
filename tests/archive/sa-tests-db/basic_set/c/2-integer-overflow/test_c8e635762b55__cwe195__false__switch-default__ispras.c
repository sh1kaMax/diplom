// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[33];
  int number = 32;

  int var;

  scanf("%d", &number);
  if (number > 32)
    number = 32;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    strncpy(string, source_string, number);
    string[32] = '\0';
    break;
  }
}
