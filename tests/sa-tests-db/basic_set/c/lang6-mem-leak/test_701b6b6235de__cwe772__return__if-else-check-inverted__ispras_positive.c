// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её возвратом из функции.
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdio.h>
#include <stdlib.h>

FILE *func(const char *path) {
  FILE *f = NULL;

  f = fopen(path, "r"); // FLAW

  if (!(f != NULL)) {
    exit(0);
  } else {
    f = NULL;
  }

  return f;
}
