// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

void func(const char *path) {
  FILE *f = NULL;

  f = fopen(path, "r"); // FLAW

  f = NULL;

  gf = f;
}
