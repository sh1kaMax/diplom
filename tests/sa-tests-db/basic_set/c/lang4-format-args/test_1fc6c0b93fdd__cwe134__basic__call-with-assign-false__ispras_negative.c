// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

void callee(int *pointer_param) { *pointer_param = 109; }

void func(int param) {
  char format[41] = "Initial format string";

  int var = 0;

  scanf("%40s", format);

  callee(&var);

  if (var > 92) {
    exit(0);
  }

  printf(format);
}
