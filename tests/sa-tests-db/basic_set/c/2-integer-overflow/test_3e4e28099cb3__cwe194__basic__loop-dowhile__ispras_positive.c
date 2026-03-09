// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
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
  char string[69];
  short number = 68;

  int var;

  scanf("%hd", &number);
  if (number > 68)
    number = 68;

  var = 0;

  do {
    var++;
  } while (var < 13);

  strncpy(string, source_string, number); // FLAW
  string[68] = '\0';
}
