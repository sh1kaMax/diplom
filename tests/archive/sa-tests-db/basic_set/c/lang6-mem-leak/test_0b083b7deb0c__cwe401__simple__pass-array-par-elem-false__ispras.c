// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free().
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void func(int param, size_t size) {
  void *f = NULL;

  int arr[100];
  int some_var = 15;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[93] = 0;

  if (some_var) {
    f = malloc(size); // FLAW
  }

  if (arr[93]) {
    if (f != NULL) {
      free(f);
    }
  }
}
