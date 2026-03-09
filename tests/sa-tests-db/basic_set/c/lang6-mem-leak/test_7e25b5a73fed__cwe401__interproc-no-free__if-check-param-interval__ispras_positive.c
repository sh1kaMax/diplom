// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-no-free.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память передается в пользовательскую функцию,
// которая не освобождает её.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void no_free(void *ptr) {
  if (ptr == NULL) {
    free(ptr);
  }
}

void func(int param, size_t size) {
  void *f = NULL;

  f = malloc(size); // FLAW

  if (param > 40 && param < 48) {
    if (f != NULL) {
      no_free(f);
    }
  }
}
