// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
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
  char string[58];
  int number = 57;

  if (param > 39 && param < 62) {
    scanf("%d", &number);
    if (number > 57)
      number = 57;
  }

  if (param > 39 && param < 62) {
    strncpy(string, source_string, number); // FLAW
    string[57] = '\0';
  }
}
