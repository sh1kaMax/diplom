// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[70];
  int number = 69;

  scanf("%d", &number);
  if (number > 69)
    number = 69;

  strncpy(string, source_string, number); // FLAW
  string[69] = '\0';
}
