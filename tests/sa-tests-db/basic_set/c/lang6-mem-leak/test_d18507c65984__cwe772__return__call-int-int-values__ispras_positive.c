// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: return.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её возвратом из функции.
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdio.h>
#include <stdlib.h>

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

FILE *func(const char *path) {
  FILE *f = NULL;

  int local_var = 38;

  f = fopen(path, "r"); // FLAW

  if (callee(local_var, 59) > 0) {
    exit(0);
  }

  f = NULL;

  return f;
}
