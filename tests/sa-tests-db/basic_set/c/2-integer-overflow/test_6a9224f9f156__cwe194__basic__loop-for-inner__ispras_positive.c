// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[90];
  short number = 89;

  int var, var2;

  scanf("%hd", &number);
  if (number > 89)
    number = 89;

  for (var = 0; var < 13; var++) {
    for (var2 = var; var2 < 10; var2++) {
      strncpy(string, source_string, number); // FLAW
      string[89] = '\0';
    }
  }
}
