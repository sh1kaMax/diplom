// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose().
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void func(int param, const char *path) {
  FILE *f = NULL;

  if (param > 23 && param < 35) {
    f = fopen(path, "r"); // FLAW
  }

  if (param <= 23 || param >= 35) {
    if (f != NULL) {
      fclose(f);
    }
  }
}
