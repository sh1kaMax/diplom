// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её записью в глобальную
// переменную.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void *gf;

void func(int param, size_t size) {
  void *f = NULL;

  int arr[100];
  arr[2] = param;
  arr[69] = 7;

  if (param) {
    f = malloc(size);
  }

  param = arr[2];

  if (param) {
    gf = f;
  }
}
