// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-free.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память освобождается в пользовательской функции.
//
// Поточный вариант: pass-array-par-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void my_free(void *ptr) { free(ptr); }

void func(int param, size_t size) {
  void *f = NULL;

  int arr[100];
  int some_var = 40;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[90] = 0;

  if (some_var) {
    f = malloc(size); // FLAW
  }

  if (arr[90]) {
    if (f != NULL) {
      my_free(f);
    }
  }
}
