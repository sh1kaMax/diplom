// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: call-with-no-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 235;
}

void func(void) {
  char format[51] = "Initial format string";

  int var = 0;

  scanf("%50s", format);

  callee(&var, -7);

  if (var > 714) {
    exit(0);
  }

  printf(format); // FLAW
}
