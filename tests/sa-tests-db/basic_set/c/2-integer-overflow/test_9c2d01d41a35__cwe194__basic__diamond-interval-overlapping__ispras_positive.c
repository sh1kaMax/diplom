// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
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
  char string[18];
  short number = 17;

  if (param > 25 && param < 53) {
    scanf("%hd", &number);
    if (number > 17)
      number = 17;
  }

  if (param > 32 && param < 40) {
    strncpy(string, source_string, number); // FLAW
    string[17] = '\0';
  }
}
