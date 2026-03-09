// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

void func(const char *path) {
  FILE *f = NULL;

  int flag = 0;

  f = fopen(path, "r");

  if (f != NULL)
    flag = 1;

  if (flag != 0)
    goto error_label;

  f = NULL;

  exit(0);

error_label:
  gf = f;
}
