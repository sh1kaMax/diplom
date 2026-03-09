// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её записью в глобальную
// переменную.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void *gf;

void func(int param, size_t size) {
  void *f = NULL;

  int arr[100];
  int some_var = 28;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[65] = 7;

  if (some_var) {
    f = malloc(size);
  }

  if (arr[param]) {
    gf = f;
  }
}
