// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
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

const char safe_format[] = "Safe format string";

int callee(int par1) {
  if (par1 > 39)
    return 20;

  return 10;
}

void func(int param) {
  char format[61] = "Initial format string";

  int local_var = -5;

  scanf("%60s", format);

  if (callee(local_var) > 10) {
    exit(0);
  }

  printf(format); // FLAW
}
