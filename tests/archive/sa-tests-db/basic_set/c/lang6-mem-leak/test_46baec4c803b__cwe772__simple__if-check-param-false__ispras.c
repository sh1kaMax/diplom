// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose().
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void func(int param, const char *path) {
  FILE *f = NULL;

  f = fopen(path, "r"); // FLAW

  if (param > 25 && param < 26) {
    if (f != NULL) {
      fclose(f);
    }
  }
}
