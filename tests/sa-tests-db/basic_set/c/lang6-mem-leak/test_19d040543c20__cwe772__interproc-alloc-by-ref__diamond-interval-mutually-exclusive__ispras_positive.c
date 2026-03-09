// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-alloc-by-ref.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор выделяется в пользовательской функции по указателю.
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void my_fopen(FILE **ptr, const char *my_path) {
  if (ptr != NULL) {
    *ptr = fopen(my_path, "r");
  }
}

void func(int param, const char *path) {
  FILE *f = NULL;

  if (param > 37 && param < 42) {
    my_fopen(&f, path); // FLAW
  }

  if (param <= 37 || param >= 42) {
    if (f != NULL) {
      fclose(f);
    }
  }
}
