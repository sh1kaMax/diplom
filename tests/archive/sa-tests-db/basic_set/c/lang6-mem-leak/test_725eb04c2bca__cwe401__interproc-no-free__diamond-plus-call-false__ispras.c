// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-no-free.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память передается в пользовательскую функцию,
// которая не освобождает её.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>

void no_free(void *ptr) {
  if (ptr == NULL) {
    free(ptr);
  }
}

int ret_func(int param1) { return param1; }

void func(int param, size_t size) {
  void *f = NULL;

  int func_res = ret_func(10);

  if (param + func_res > 12) {
    f = malloc(size); // FLAW
  }

  if (param + func_res < 12) {
    if (f != NULL) {
      no_free(f);
    }
  }
}
