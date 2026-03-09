// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

void callee(int *pointer_param) { *pointer_param = 420; }

void func(const char *path) {
  FILE *f = NULL;

  int var = 0;

  f = fopen(path, "r");

  callee(&var);

  if (var > 963) {
    exit(0);
  }

  gf = f;
}
