// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-free.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память освобождается в пользовательской функции.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void my_free(void *ptr) { free(ptr); }

void func(int param, size_t size) {
  void *f = NULL;

  int arr[100];
  arr[42] = !param;
  arr[71] = 7;

  if (param) {
    f = malloc(size); // FLAW
  }

  param = arr[42];

  if (param) {
    if (f != NULL) {
      my_free(f);
    }
  }
}
