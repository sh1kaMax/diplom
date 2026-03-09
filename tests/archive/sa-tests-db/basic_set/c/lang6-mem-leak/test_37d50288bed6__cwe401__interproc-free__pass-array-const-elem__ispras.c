// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-free.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память освобождается в пользовательской функции.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void my_free(void *ptr) { free(ptr); }

void func(int param, size_t size) {
  void *f = NULL;

  int arr[100];
  arr[45] = param;
  arr[96] = 7;

  if (param) {
    f = malloc(size);
  }

  param = arr[45];

  if (param) {
    if (f != NULL) {
      my_free(f);
    }
  }
}
