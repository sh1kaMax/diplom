// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[58];
  int number = 57;

  number = 57;

  scanf("%d", &number);
  if (number > 57)
    number = 57;

  strncpy(string, source_string, number); // FLAW
  string[57] = '\0';
}
