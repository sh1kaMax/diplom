// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её возвратом из функции.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdio.h>
#include <stdlib.h>

FILE *func(const char *path) {
  FILE *f = NULL;

  int var;

  f = fopen(path, "r"); // FLAW

  var = 0;

  do {
    var++;
  } while (var < 20);

  f = NULL;

  return f;
}
