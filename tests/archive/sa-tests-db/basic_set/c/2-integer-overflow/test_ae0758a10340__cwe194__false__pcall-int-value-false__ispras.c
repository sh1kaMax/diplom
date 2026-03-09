// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: pcall-int-value-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// успешна и выполнение прекращается. Вызов функции осуществляется с помощью
// указателя.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int callee(int par1) {
  if (par1 > 42)
    return 20;

  return 10;
}

void func(void) {
  char string[11];
  short number = 10;

  int local_var = -3;
  int (*func_ptr)(int) = &callee;

  scanf("%hd", &number);
  if (number > 10)
    number = 10;

  if (func_ptr(local_var) == 10) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[10] = '\0';
}
