// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её возвратом из функции.
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdio.h>
#include <stdlib.h>

void *func(int param, size_t size) {
  void *f = NULL;

  if (param % 2 == 0) {
    f = malloc(size);
  }

  if (param % 2 == 1) {
    f = NULL;
  }

  return f;
}
