// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её записью в глобальную
// переменную.
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdio.h>
#include <stdlib.h>

void *gf;

void func(size_t size) {
  void *f = NULL;

  int var;

  f = malloc(size);

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    gf = f;
    break;
  }
}
