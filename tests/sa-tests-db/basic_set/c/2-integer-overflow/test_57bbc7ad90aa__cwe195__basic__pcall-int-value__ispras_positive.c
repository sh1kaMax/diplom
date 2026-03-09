// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: pcall-int-value.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от локальной переменной, переданной в функцию по
// значению; возвращаемое из вызываемой функции значение больше 20, если
// параметр больше константы ([10;20]), поэтому проверка в вызывающей функции
// неуспешна и выполнение достигает стока. Вызов функции осуществляется по
// указателю.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int callee(int par1) {
  if (par1 > 66)
    return 20;

  return 10;
}

void func(void) {
  char string[43];
  int number = 42;

  int local_var = -5;
  int (*func_ptr)(int) = &callee;

  scanf("%d", &number);
  if (number > 42)
    number = 42;

  if (func_ptr(local_var) > 10) {
    exit(0);
  }

  strncpy(string, source_string, number); // FLAW
  string[42] = '\0';
}
