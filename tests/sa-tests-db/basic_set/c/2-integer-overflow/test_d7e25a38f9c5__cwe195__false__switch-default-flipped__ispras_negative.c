// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[17];
  int number = 16;

  int var;

  scanf("%d", &number);
  if (number > 16)
    number = 16;

  var = 0;

  switch (var) {
  default:
    strncpy(string, source_string, number);
    string[16] = '\0';
    break;
  case 0:
    exit(0);
    break;
  }
}
