// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose().
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdio.h>
#include <stdlib.h>

void func(const char *path) {
  FILE *f = NULL;

  int var;

  f = fopen(path, "r");

  var = 0;

  do {
    var++;
  } while (var < 16);

  if (f != NULL) {
    fclose(f);
  }
}
