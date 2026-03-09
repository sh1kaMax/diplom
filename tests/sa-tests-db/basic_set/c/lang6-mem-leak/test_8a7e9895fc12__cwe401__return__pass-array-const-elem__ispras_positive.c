// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её возвратом из функции.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void *func(int param, size_t size) {
  void *f = NULL;

  int arr[100];
  arr[17] = param;
  arr[97] = 7;

  if (param) {
    f = malloc(size); // FLAW
  }

  param = arr[17];

  if (param) {
    f = NULL;
  }

  return f;
}
