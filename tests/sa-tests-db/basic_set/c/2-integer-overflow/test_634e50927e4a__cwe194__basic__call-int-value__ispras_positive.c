// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-int-value.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int callee(int par1) {
  if (par1 > 46)
    return 20;

  return 10;
}

void func(int param) {
  char string[87];
  short number = 86;

  int local_var = 4;

  scanf("%hd", &number);
  if (number > 86)
    number = 86;

  if (callee(local_var) > 10) {
    exit(0);
  }

  strncpy(string, source_string, number); // FLAW
  string[86] = '\0';
}
