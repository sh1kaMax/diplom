// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[49];
  int number = 48;

  if (param > 37 && param < 69) {
    scanf("%d", &number);
    if (number > 48)
      number = 48;
  }

  if (param > 63 && param < 67) {
    strncpy(string, source_string, number); // FLAW
    string[48] = '\0';
  }
}
