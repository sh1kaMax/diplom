// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// простых условий, результат которых зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[68];
  short number = 67;

  if (param > 11) {
    scanf("%hd", &number);
    if (number > 67)
      number = 67;
  }

  if (param <= 11) {
    strncpy(string, source_string, number);
    string[67] = '\0';
  }
}
