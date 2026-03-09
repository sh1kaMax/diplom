// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-leak.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Перезапись осуществляется в пользовательской функции.
//
// Поточный вариант: error-path-external-filtered.c
// Достижимый путь от источника до стока с фильтрацией и проверкой результата
// вызова неизвестной внешней функции между ними, переход по метке со стоком в
// случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

int external_func(void);

void leak_func(FILE **ptr) {
  if (ptr != NULL) {
    *ptr = NULL;
  }
}

void func(const char *path) {
  FILE *f = NULL;

  f = fopen(path, "r"); // FLAW

  if (external_func()) {

    leak_func(&f);

    goto error_label;
  }

  exit(0);

error_label:
  if (f != NULL) {
    fclose(f);
  }
}
