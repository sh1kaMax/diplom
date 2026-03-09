// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-free.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор освобождается в пользовательской функции.
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void my_fclose(FILE *ptr) { fclose(ptr); }

void func(int param, const char *path) {
  FILE *f = NULL;

  if (param > 29 && param < 76) {
    f = fopen(path, "r"); // FLAW
  }

  if (param > 65 && param < 72) {
    if (f != NULL) {
      my_fclose(f);
    }
  }
}
