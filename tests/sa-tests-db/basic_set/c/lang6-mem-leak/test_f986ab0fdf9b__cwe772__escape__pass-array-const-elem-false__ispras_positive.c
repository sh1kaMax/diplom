// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

void func(int param, const char *path) {
  FILE *f = NULL;

  int arr[100];
  arr[12] = !param;
  arr[76] = 7;

  if (param) {
    f = fopen(path, "r"); // FLAW
  }

  param = arr[12];

  if (param) {
    gf = f;
  }
}
