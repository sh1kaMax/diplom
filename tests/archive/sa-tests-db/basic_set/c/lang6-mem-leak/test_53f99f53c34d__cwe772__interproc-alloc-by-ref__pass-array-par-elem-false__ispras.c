// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-alloc-by-ref.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор выделяется в пользовательской функции по указателю.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void my_fopen(FILE **ptr, const char *my_path) {
  if (ptr != NULL) {
    *ptr = fopen(my_path, "r");
  }
}

void func(int param, const char *path) {
  FILE *f = NULL;

  int arr[100];
  int some_var = 12;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[70] = 0;

  if (some_var) {
    my_fopen(&f, path); // FLAW
  }

  if (arr[70]) {
    if (f != NULL) {
      fclose(f);
    }
  }
}
