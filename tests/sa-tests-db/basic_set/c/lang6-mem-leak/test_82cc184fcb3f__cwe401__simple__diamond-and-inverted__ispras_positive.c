// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free().
//
// Поточный вариант: diamond-and-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// с использованием битового и.

#include <stdio.h>
#include <stdlib.h>

void func(int param, size_t size) {
  void *f = NULL;

  if ((param & 0x10) > 0) {
    f = malloc(size); // FLAW
  }

  if ((param & 0x10) == 0) {
    if (f != NULL) {
      free(f);
    }
  }
}
