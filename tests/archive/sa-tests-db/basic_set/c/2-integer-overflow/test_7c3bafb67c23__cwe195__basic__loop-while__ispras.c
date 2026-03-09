// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[64];
  int number = 63;

  int var;

  scanf("%d", &number);
  if (number > 63)
    number = 63;

  var = 0;

  while (var < 11)
    var++;

  strncpy(string, source_string, number); // FLAW
  string[63] = '\0';
}
