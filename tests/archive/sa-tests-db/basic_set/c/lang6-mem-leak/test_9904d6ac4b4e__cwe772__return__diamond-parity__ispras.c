// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её возвратом из функции.
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdio.h>
#include <stdlib.h>

FILE *func(int param, const char *path) {
  FILE *f = NULL;

  if (param % 2) {
    f = fopen(path, "r"); // FLAW
  }

  if (param % 2) {
    f = NULL;
  }

  return f;
}
