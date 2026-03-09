// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  int iter_var;

  char string[66];
  short number = 65;

  for (iter_var = 0; iter_var < 26; iter_var++) {
    scanf("%hd", &number);
    if (number > 65)
      number = 65;

    strncpy(string, source_string, number); // FLAW
    string[65] = '\0';
  }
}
