// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

int ret_func(int param1) { return param1; }

void func(int param, const char *path) {
  FILE *f = NULL;

  int func_res = ret_func(10);

  if (param + func_res > 5) {
    f = fopen(path, "r"); // FLAW
  }

  if (param + func_res < 5) {
    gf = f;
  }
}
