// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int callee(int par1) {
  if (par1 > 53)
    return 20;

  return 10;
}

void func(void) {
  char string[63];
  short number = 62;

  int local_var = 2;

  scanf("%hd", &number);
  if (number > 62)
    number = 62;

  if (callee(local_var) == 10) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[62] = '\0';
}
