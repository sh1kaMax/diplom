// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её записью в глобальную
// переменную.
//
// Поточный вариант: call-int-int-values.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции неуспешна и выполнение
// достигает стока

#include <stdio.h>
#include <stdlib.h>

void *gf;

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

void func(size_t size) {
  void *f = NULL;

  int local_var = 17;

  f = malloc(size);

  if (callee(local_var, 33) > 0) {
    exit(0);
  }

  gf = f;
}
