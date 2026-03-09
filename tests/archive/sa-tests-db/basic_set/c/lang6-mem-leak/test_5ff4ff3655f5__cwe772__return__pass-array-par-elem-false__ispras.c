// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её возвратом из функции.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

FILE *func(int param, const char *path) {
  FILE *f = NULL;

  int arr[100];
  int some_var = 36;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[90] = 0;

  if (some_var) {
    f = fopen(path, "r");
  }

  if (arr[90]) {
    f = NULL;
  }

  return f;
}
