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
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void no_free(void *ptr) {
  if (ptr == NULL) {
    free(ptr);
  }
}

void func(int param, size_t size) {
  void *f = NULL;

  if (param > 4 && param < 53) {
    f = malloc(size); // FLAW
  }

  if (param > 4 && param < 53) {
    if (f != NULL) {
      no_free(f);
    }
  }
}
