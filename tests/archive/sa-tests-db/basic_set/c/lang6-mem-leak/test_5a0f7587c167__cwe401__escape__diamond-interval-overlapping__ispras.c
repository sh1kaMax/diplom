// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её записью в глобальную
// переменную.
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void *gf;

void func(int param, size_t size) {
  void *f = NULL;

  if (param > 14 && param < 58) {
    f = malloc(size); // FLAW
  }

  if (param > 51 && param < 61) {
    gf = f;
  }
}
