// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

void func(int param, const char *path) {
  FILE *f = NULL;

  if (param % 2) {
    f = fopen(path, "r");
  }

  if (param % 2) {
    gf = f;
  }
}
