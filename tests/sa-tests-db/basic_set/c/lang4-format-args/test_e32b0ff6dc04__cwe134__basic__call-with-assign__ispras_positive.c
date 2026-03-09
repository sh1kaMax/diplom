// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void callee(int *pointer_param) { *pointer_param = 294; }

void func(int param) {
  char format[35] = "Initial format string";

  int var = 0;

  scanf("%34s", format);

  callee(&var);

  if (var > 340) {
    exit(0);
  }

  printf(format); // FLAW
}
