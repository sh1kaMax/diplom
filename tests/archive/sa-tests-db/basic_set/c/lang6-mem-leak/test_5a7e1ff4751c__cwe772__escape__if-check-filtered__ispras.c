// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

void func(const char *path) {
  FILE *f = NULL;

  f = fopen(path, "r"); // FLAW

  if (f != NULL) {
    f = NULL;
  }

  gf = f;
}
