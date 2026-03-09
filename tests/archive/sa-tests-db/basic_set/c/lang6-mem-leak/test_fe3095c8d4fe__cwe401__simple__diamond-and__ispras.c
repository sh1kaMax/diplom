// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free().
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdio.h>
#include <stdlib.h>

void func(int param, size_t size) {
  void *f = NULL;

  if (param & 0x1D) {
    f = malloc(size);
  }

  if (param & 0x1D) {
    if (f != NULL) {
      free(f);
    }
  }
}
