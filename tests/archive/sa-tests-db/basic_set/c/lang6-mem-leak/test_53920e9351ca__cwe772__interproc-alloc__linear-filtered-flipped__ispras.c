// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-alloc.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор возвращается из пользовательской функции.
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <stdio.h>
#include <stdlib.h>

FILE *my_fopen(const char *my_path) {
  if (my_path != NULL) {
    return fopen(my_path, "r");
  } else {
    return NULL;
  }
}

void func(const char *path) {
  FILE *f = NULL;

  f = NULL;

  f = my_fopen(path);

  if (f != NULL) {
    fclose(f);
  }
}
