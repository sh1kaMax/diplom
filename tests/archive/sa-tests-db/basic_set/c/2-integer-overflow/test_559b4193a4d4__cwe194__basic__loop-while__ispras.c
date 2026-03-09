// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[35];
  short number = 34;

  int var;

  scanf("%hd", &number);
  if (number > 34)
    number = 34;

  var = 0;

  while (var < 11)
    var++;

  strncpy(string, source_string, number); // FLAW
  string[34] = '\0';
}
