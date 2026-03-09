// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[29];
  int number = 28;

  int var;

  scanf("%d", &number);
  if (number > 28)
    number = 28;

  var = 0;

  for (var = 0; var < 19; var++)
    ;

  strncpy(string, source_string, number); // FLAW
  string[28] = '\0';
}
