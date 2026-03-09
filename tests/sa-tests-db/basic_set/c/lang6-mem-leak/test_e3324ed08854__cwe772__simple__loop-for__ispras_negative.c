// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose().
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>

void func(const char *path) {
  FILE *f = NULL;

  int var;

  f = fopen(path, "r");

  var = 0;

  for (var = 0; var < 16; var++)
    ;

  if (f != NULL) {
    fclose(f);
  }
}
