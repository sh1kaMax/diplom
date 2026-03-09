// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её записью в глобальную
// переменную.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void *gf;

void func(int param, size_t size) {
  void *f = NULL;

  f = malloc(size); // FLAW

  if (param > 39 && param < 55) {
    gf = f;
  }
}
