// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-leak.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Перезапись осуществляется в пользовательской функции.
//
// Поточный вариант: error-path-check-flag-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, установка флага при истинности проверки, фильтрация и
// последующий переход по метке со стоком.

#include <stdio.h>
#include <stdlib.h>

void leak_func(FILE **ptr) {
  if (ptr != NULL) {
    *ptr = NULL;
  }
}

void func(const char *path) {
  FILE *f = NULL;

  int flag = 0;

  f = fopen(path, "r"); // FLAW

  if (f != NULL)
    flag = 1;

  if (flag != 0) {

    leak_func(&f);

    goto error_label;
  }

  exit(0);

error_label:
  if (f != NULL) {
    fclose(f);
  }
}
