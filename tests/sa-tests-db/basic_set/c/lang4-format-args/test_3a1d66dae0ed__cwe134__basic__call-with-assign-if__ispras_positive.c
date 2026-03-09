// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 320;
}

void func(int param) {
  char format[63] = "Initial format string";

  int var = 0;

  scanf("%62s", format);

  callee(&var, 10);

  if (var > 741) {
    exit(0);
  }

  printf(format); // FLAW
}
