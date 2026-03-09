// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[33];
  int number = 32;

  int var, var2;

  scanf("%d", &number);
  if (number > 32)
    number = 32;

  for (var = 0; var < 14; var++) {
    for (var2 = var; var2 < 18; var2++) {
      strncpy(string, source_string, number); // FLAW
      string[32] = '\0';
    }
  }
}
