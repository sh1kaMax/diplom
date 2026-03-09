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

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 159;
}

void func(int param) {
  char format[42] = "Initial format string";

  int var = 0;

  scanf("%41s", format);

  callee(&var, -6);

  if (var > 609) {
    exit(0);
  }

  printf(format); // FLAW
}
