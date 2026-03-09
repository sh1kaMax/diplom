// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её возвратом из функции.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdio.h>
#include <stdlib.h>

void *func(size_t size) {
  void *f = NULL;

  int flag = 0;

  f = malloc(size); // FLAW

  if (f != NULL)
    flag = 1;

  if (flag != 0)
    goto error_label;

  f = NULL;

  exit(0);

error_label:
  f = NULL;

  return f;
}
