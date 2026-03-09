// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-no-free.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор передается в пользовательскую функцию, которая не
// освобождает его.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>

void no_fclose(FILE *ptr) {
  if (ptr == NULL) {
    fclose(ptr);
  }
}

int ret_func(int param1) { return param1; }

void func(int param, const char *path) {
  FILE *f = NULL;

  int func_res = ret_func(10);

  if (param + func_res > 11) {
    f = fopen(path, "r"); // FLAW
  }

  if (param + func_res > 11) {
    if (f != NULL) {
      no_fclose(f);
    }
  }
}
