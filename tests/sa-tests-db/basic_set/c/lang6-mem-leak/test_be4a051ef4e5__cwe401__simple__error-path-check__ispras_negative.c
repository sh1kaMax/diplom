// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free().
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

void func(size_t size) {
  void *f = NULL;

  f = malloc(size);

  if (f != NULL)
    goto error_label;

  f = NULL;

  exit(0);

error_label:
  if (f != NULL) {
    free(f);
  }
}
