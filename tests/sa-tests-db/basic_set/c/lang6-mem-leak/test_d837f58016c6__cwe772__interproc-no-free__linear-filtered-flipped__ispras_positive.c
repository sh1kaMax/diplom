// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-no-free.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор передается в пользовательскую функцию, которая не
// освобождает его.
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <stdio.h>
#include <stdlib.h>

void no_fclose(FILE *ptr) {
  if (ptr == NULL) {
    fclose(ptr);
  }
}

void func(const char *path) {
  FILE *f = NULL;

  f = NULL;

  f = fopen(path, "r"); // FLAW

  if (f != NULL) {
    no_fclose(f);
  }
}
