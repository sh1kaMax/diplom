// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-alloc.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память возвращается из пользовательской функции.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t my_size) {
  if (my_size > 0) {
    return malloc(my_size);
  } else {
    return NULL;
  }
}

void func(int param, size_t size) {
  void *f = NULL;

  f = my_malloc(size); // FLAW

  if (param > 34) {
    if (f != NULL) {
      free(f);
    }
  }
}
