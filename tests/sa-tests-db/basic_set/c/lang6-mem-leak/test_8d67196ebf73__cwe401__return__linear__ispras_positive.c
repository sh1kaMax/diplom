// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её возвратом из функции.
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdio.h>
#include <stdlib.h>

void *func(size_t size) {
  void *f = NULL;

  f = malloc(size); // FLAW

  f = NULL;

  return f;
}
