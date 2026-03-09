// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

void func(void) {
  char format[40] = "Initial format string";

  int local_var = 31;

  scanf("%39s", format);

  if (callee(local_var, 178) > 0) {
    exit(0);
  }

  printf(format); // FLAW
}
