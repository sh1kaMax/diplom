// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её возвратом из функции.
//
// Поточный вариант: if-else-check-inverted-filtered.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdio.h>
#include <stdlib.h>

void *func(size_t size) {
  void *f = NULL;

  f = malloc(size); // FLAW

  if (!(f != NULL)) {
    f = NULL;
  } else {
    f = NULL;
  }

  return f;
}
