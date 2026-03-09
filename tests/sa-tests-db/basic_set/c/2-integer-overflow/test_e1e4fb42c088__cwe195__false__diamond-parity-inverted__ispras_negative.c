// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[91];
  int number = 90;

  if (param % 2 == 0) {
    scanf("%d", &number);
    if (number > 90)
      number = 90;
  }

  if (param % 2 == 1) {
    strncpy(string, source_string, number);
    string[90] = '\0';
  }
}
