// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[71];
  int number = 70;

  if (param & 0x1D) {
    scanf("%d", &number);
    if (number > 70)
      number = 70;
  }

  if (param & 0x1D) {
    strncpy(string, source_string, number); // FLAW
    string[70] = '\0';
  }
}
