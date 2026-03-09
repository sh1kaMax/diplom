// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose().
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdio.h>
#include <stdlib.h>

void func(const char *path) {
  FILE *f = NULL;

  int var;

  f = fopen(path, "r");

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    if (f != NULL) {
      fclose(f);
    }
    break;
  }
}
