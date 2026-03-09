// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-alloc-by-ref.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Память выделяется в пользовательской функции по указателю.
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdio.h>
#include <stdlib.h>

void my_malloc(void **ptr, size_t my_size) {
  if (ptr != NULL) {
    *ptr = malloc(my_size);
  }
}

void func(int param, size_t size) {
  void *f = NULL;

  if (param % 2) {
    my_malloc(&f, size);
  }

  if (param % 2) {
    if (f != NULL) {
      free(f);
    }
  }
}
