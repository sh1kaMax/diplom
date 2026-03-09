// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-free.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память освобождается в пользовательской функции.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>

void my_free(void *ptr) { free(ptr); }

int ret_func(int param1) { return param1; }

void func(int param, size_t size) {
  void *f = NULL;

  int func_res = ret_func(10);

  if (param + func_res > 5) {
    f = malloc(size);
  }

  if (param + func_res > 5) {
    if (f != NULL) {
      my_free(f);
    }
  }
}
