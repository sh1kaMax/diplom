// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её возвратом из функции.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdio.h>
#include <stdlib.h>

FILE *func(const char *path) {
  FILE *f = NULL;

  f = fopen(path, "r"); // FLAW

  f = NULL;

  f = NULL;

  return f;
}
