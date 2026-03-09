// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-leak.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Перезапись осуществляется в пользовательской функции.
//
// Поточный вариант: if-else-check-inverted-filtered.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdio.h>
#include <stdlib.h>

void leak_func(FILE **ptr) {
  if (ptr != NULL) {
    *ptr = NULL;
  }
}

void func(const char *path) {
  FILE *f = NULL;

  f = fopen(path, "r");

  if (!(f != NULL)) {
    leak_func(&f);
  } else {
    if (f != NULL) {
      fclose(f);
    }
  }
}
