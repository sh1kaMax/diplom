// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[45];
  short number = 44;

  if (param > 20 && param < 37) {
    scanf("%hd", &number);
    if (number > 44)
      number = 44;
  }

  if (param > 20 && param < 37) {
    strncpy(string, source_string, number); // FLAW
    string[44] = '\0';
  }
}
