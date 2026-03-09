// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

void func(int param, const char *path) {
  FILE *f = NULL;

  int arr[100];
  int some_var = 31;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[62] = 0;

  if (some_var) {
    f = fopen(path, "r"); // FLAW
  }

  if (arr[62]) {
    gf = f;
  }
}
