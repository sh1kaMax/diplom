// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[46];
  short number = 45;

  if (param % 2) {
    scanf("%hd", &number);
    if (number > 45)
      number = 45;
  }

  if (param % 2) {
    strncpy(string, source_string, number); // FLAW
    string[45] = '\0';
  }
}
