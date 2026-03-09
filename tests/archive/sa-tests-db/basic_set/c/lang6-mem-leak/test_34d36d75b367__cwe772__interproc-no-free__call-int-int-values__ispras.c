// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-no-free.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор передается в пользовательскую функцию, которая не
// освобождает его.
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdio.h>
#include <stdlib.h>

void no_fclose(FILE *ptr) {
  if (ptr == NULL) {
    fclose(ptr);
  }
}

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

void func(const char *path) {
  FILE *f = NULL;

  int local_var = 64;

  f = fopen(path, "r"); // FLAW

  if (callee(local_var, 107) > 0) {
    exit(0);
  }

  if (f != NULL) {
    no_fclose(f);
  }
}
