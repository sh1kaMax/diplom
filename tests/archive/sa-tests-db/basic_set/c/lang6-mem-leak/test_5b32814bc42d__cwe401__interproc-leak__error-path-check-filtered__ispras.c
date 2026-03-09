// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-leak.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Перезапись осуществляется в пользовательской функции.
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdio.h>
#include <stdlib.h>

void leak_func(void **ptr) {
  if (ptr != NULL) {
    *ptr = NULL;
  }
}

void func(size_t size) {
  void *f = NULL;

  f = malloc(size); // FLAW

  if (f != NULL) {

    leak_func(&f);

    goto error_label;
  }

  exit(0);

error_label:
  if (f != NULL) {
    free(f);
  }
}
