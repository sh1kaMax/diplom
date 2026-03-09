// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
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

const char safe_format[] = "Safe format string";

int callee(int par1) {
  if (par1 > 41)
    return 20;

  return 10;
}

void func(void) {
  char format[35] = "Initial format string";

  int local_var = 3;
  int (*func_ptr)(int) = &callee;

  scanf("%34s", format);

  if (func_ptr(local_var) == 10) {
    exit(0);
  }

  printf(format);
}
