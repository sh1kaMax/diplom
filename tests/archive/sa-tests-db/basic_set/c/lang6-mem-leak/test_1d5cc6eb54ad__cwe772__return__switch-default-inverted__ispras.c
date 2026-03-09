// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её возвратом из функции.
//
// Поточный вариант: switch-default-inverted.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdio.h>
#include <stdlib.h>

FILE *func(const char *path) {
  FILE *f = NULL;

  int var;

  f = fopen(path, "r"); // FLAW

  var = 0;

  switch (var) {
  case 0:
    f = NULL;
    break;
  default:
    exit(0);
    break;
  }

  return f;
}
