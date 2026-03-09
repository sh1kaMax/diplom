// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

void func(int param, const char *path) {
  FILE *f = NULL;

  if (param > 48 && param < 57) {
    f = fopen(path, "r"); // FLAW
  }

  if (param <= 48 || param >= 57) {
    gf = f;
  }
}
