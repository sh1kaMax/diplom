// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-no-free.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор передается в пользовательскую функцию, которая не
// освобождает его.
//
// Поточный вариант: diamond-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// простых условий, результат которых зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void no_fclose(FILE *ptr) {
  if (ptr == NULL) {
    fclose(ptr);
  }
}

void func(int param, const char *path) {
  FILE *f = NULL;

  if (param > 15) {
    f = fopen(path, "r"); // FLAW
  }

  if (param <= 15) {
    if (f != NULL) {
      no_fclose(f);
    }
  }
}
