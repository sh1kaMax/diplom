// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её записью в глобальную
// переменную.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>

void *gf;

int ret_func(int param1) { return param1; }

void func(int param, size_t size) {
  void *f = NULL;

  int func_res = ret_func(10);

  if (param + func_res > 8) {
    f = malloc(size);
  }

  if (param + func_res > 8) {
    gf = f;
  }
}
