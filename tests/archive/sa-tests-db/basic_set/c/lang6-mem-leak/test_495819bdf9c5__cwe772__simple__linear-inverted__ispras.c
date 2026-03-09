// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose().
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <stdio.h>
#include <stdlib.h>

void func(const char *path) {
  FILE *f = NULL;

  if (f != NULL) {
    fclose(f);
  }

  f = fopen(path, "r"); // FLAW
}
