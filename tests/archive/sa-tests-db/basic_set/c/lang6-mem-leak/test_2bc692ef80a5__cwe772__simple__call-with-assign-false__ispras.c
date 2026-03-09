// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose().
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdio.h>
#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 499; }

void func(const char *path) {
  FILE *f = NULL;

  int var = 0;

  f = fopen(path, "r");

  callee(&var);

  if (var > 329) {
    exit(0);
  }

  if (f != NULL) {
    fclose(f);
  }
}
