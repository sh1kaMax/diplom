// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

void func(void) {
  char string[54];
  int number = 53;

  int var;

  scanf("%d", &number);
  if (number > 53)
    number = 53;

  var = 0;

  do {
    var++;
  } while (var < 10);

  strncpy(string, source_string, number); // FLAW
  string[53] = '\0';
}
