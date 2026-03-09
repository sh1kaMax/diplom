// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-free.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память освобождается в пользовательской функции.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>

void my_free(void *ptr) { free(ptr); }

void func(size_t size) {
  void *f = NULL;

  int var;

  f = malloc(size);

  var = 0;

  for (var = 0; var < 19; var++)
    ;

  if (f != NULL) {
    my_free(f);
  }
}
