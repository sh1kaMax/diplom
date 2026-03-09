// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose().
//
// Поточный вариант: diamond-overlapping-inverted.c
// Недостижимый путь от источника до стока с проверками несовместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void func(int param, const char *path) {
  FILE *f = NULL;

  if (param > 35) {
    f = fopen(path, "r"); // FLAW
  }

  if (param < 12) {
    if (f != NULL) {
      fclose(f);
    }
  }
}
