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
// Поточный вариант: call-global.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения глобальной переменной, значение которой
// устанавливается перед вызовом; возвращаемое из вызываемой функции значение
// нулевое, поэтому проверка в вызывающей функции неуспешна и выполнение
// достигает стока.

#include <stdio.h>
#include <stdlib.h>

void no_fclose(FILE *ptr) {
  if (ptr == NULL) {
    fclose(ptr);
  }
}

int global_var = 0;

int callee(void) {
  if (global_var > 0)
    return 1;
  else
    return 0;
}

void func(const char *path) {
  FILE *f = NULL;

  global_var = -1;

  f = fopen(path, "r"); // FLAW

  if (callee()) {
    exit(0);
  }

  if (f != NULL) {
    no_fclose(f);
  }
}
