// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  int iter_var;

  char string[48];
  int number = 47;

  for (iter_var = 4; iter_var < 11; iter_var++) {
    scanf("%d", &number);
    if (number > 47)
      number = 47;

    strncpy(string, source_string, number); // FLAW
    string[47] = '\0';
  }
}
