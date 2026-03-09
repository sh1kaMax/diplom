// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(int param) {
  char string[89];
  int number = 88;

  if (param > 31 && param < 45) {
    scanf("%d", &number);
    if (number > 88)
      number = 88;
  }

  if (param <= 31 || param >= 45) {
    strncpy(string, source_string, number);
    string[88] = '\0';
  }
}
