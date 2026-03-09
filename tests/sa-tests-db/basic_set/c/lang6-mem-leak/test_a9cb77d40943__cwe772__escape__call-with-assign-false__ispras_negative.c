// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

void callee(int *pointer_param) { *pointer_param = 107; }

void func(const char *path) {
  FILE *f = NULL;

  int var = 0;

  f = fopen(path, "r");

  callee(&var);

  if (var > 1) {
    exit(0);
  }

  gf = f;
}
