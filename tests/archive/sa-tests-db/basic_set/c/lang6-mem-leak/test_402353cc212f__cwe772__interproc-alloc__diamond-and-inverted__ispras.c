// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-alloc.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор возвращается из пользовательской функции.
//
// Поточный вариант: diamond-and-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// с использованием битового и.

#include <stdio.h>
#include <stdlib.h>

FILE *my_fopen(const char *my_path) {
  if (my_path != NULL) {
    return fopen(my_path, "r");
  } else {
    return NULL;
  }
}

void func(int param, const char *path) {
  FILE *f = NULL;

  if ((param & 0x10) > 0) {
    f = my_fopen(path); // FLAW
  }

  if ((param & 0x10) == 0) {
    if (f != NULL) {
      fclose(f);
    }
  }
}
