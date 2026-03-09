// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-alloc-by-ref.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Память выделяется в пользовательской функции по указателю.
//
// Поточный вариант: loop-while.c
// Участок кода от источника до стока с циклом while с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>

void my_malloc(void **ptr, size_t my_size) {
  if (ptr != NULL) {
    *ptr = malloc(my_size);
  }
}

void func(size_t size) {
  void *f = NULL;

  int var;

  my_malloc(&f, size);

  var = 0;

  while (var < 12)
    var++;

  if (f != NULL) {
    free(f);
  }
}
