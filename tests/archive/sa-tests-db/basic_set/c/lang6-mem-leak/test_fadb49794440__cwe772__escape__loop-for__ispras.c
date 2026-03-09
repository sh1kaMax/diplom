// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

void func(const char *path) {
  FILE *f = NULL;

  int var;

  f = fopen(path, "r");

  var = 0;

  for (var = 0; var < 11; var++)
    ;

  gf = f;
}
