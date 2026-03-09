// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка файлового дескриптора при перезаписи переменной,
// хранящей открытый дескриптор, перед её записью в глобальную переменную.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdio.h>
#include <stdlib.h>

FILE *gf;

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(const char *path) {
  FILE *f = NULL;

  int local_var = 97;

  f = fopen(path, "r");

  if (callee(local_var, 200) > 0) {
    exit(0);
  }

  gf = f;
}
