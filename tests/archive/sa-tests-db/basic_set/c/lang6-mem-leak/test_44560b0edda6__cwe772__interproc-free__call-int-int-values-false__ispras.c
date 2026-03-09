// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-free.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор освобождается в пользовательской функции.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdio.h>
#include <stdlib.h>

void my_fclose(FILE *ptr) { fclose(ptr); }

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(const char *path) {
  FILE *f = NULL;

  int local_var = 84;

  f = fopen(path, "r");

  if (callee(local_var, 152) > 0) {
    exit(0);
  }

  if (f != NULL) {
    my_fclose(f);
  }
}
