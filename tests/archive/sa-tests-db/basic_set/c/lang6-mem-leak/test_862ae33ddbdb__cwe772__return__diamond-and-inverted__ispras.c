// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её возвратом из функции.
//
// Поточный вариант: diamond-and-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// с использованием битового и.

#include <stdio.h>
#include <stdlib.h>

FILE *func(int param, const char *path) {
  FILE *f = NULL;

  if ((param & 0x10) > 0) {
    f = fopen(path, "r");
  }

  if ((param & 0x10) == 0) {
    f = NULL;
  }

  return f;
}
