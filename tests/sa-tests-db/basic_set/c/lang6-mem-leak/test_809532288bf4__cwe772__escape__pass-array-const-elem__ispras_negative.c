// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

void func(int param, const char *path) {
  FILE *f = NULL;

  int arr[100];
  arr[24] = param;
  arr[95] = 7;

  if (param) {
    f = fopen(path, "r");
  }

  param = arr[24];

  if (param) {
    gf = f;
  }
}
