// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-leak.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Перезапись осуществляется в пользовательской функции.
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <stdio.h>
#include <stdlib.h>

void leak_func(void **ptr) {
  if (ptr != NULL) {
    *ptr = NULL;
  }
}

void func(size_t size) {
  void *f = NULL;

  leak_func(&f);

  f = malloc(size);

  if (f != NULL) {
    free(f);
  }
}
