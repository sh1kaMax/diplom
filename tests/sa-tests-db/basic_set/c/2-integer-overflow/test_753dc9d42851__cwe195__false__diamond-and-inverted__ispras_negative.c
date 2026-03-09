// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-and-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// с использованием битового и. Приоритет битового и ниже, чем у сравнения,
// поэтому второе условие всегда ложное.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[95];
  int number = 94;

  if ((param & 0x10) > 0) {
    scanf("%d", &number);
    if (number > 94)
      number = 94;
  }

  if ((param & 0x10) == 0) {
    strncpy(string, source_string, number);
    string[94] = '\0';
  }
}
