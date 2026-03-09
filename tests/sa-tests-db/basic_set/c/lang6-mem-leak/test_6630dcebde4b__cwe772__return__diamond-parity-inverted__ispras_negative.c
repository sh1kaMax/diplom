// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её возвратом из функции.
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdio.h>
#include <stdlib.h>

FILE *func(int param, const char *path) {
  FILE *f = NULL;

  if (param % 2 == 0) {
    f = fopen(path, "r");
  }

  if (param % 2 == 1) {
    f = NULL;
  }

  return f;
}
