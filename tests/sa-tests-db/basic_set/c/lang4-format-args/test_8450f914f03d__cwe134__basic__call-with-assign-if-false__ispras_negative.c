// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 455;
}

void func(void) {
  char format[47] = "Initial format string";

  int var = 0;

  scanf("%46s", format);

  callee(&var, 3);

  if (var > 144) {
    exit(0);
  }

  printf(format);
}
