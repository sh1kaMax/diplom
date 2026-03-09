// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её возвратом из функции.
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>

void *func(size_t size) {
  void *f = NULL;

  int var;

  f = malloc(size); // FLAW

  var = 0;

  for (var = 0; var < 12; var++)
    ;

  f = NULL;

  return f;
}
