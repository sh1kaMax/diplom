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
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

int external_func(void);

void no_free(void *ptr) {
  if (ptr == NULL) {
    free(ptr);
  }
}

void func(size_t size) {
  void *f = NULL;

  f = malloc(size); // FLAW

  if (external_func()) {

    f = NULL;

    goto error_label;
  }

  exit(0);

error_label:
  if (f != NULL) {
    no_free(f);
  }
}
