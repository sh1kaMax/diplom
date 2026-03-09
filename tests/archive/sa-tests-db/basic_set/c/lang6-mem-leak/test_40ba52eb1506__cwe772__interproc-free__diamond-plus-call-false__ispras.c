// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-free.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор освобождается в пользовательской функции.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>

void my_fclose(FILE *ptr) { fclose(ptr); }

int ret_func(int param1) { return param1; }

void func(int param, const char *path) {
  FILE *f = NULL;

  int func_res = ret_func(10);

  if (param + func_res > 50) {
    f = fopen(path, "r"); // FLAW
  }

  if (param + func_res < 50) {
    if (f != NULL) {
      my_fclose(f);
    }
  }
}
