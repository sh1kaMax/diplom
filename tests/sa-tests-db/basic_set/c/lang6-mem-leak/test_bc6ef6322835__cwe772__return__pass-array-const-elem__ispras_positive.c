// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её возвратом из функции.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

FILE *func(int param, const char *path) {
  FILE *f = NULL;

  int arr[100];
  arr[41] = param;
  arr[63] = 7;

  if (param) {
    f = fopen(path, "r"); // FLAW
  }

  param = arr[41];

  if (param) {
    f = NULL;
  }

  return f;
}
