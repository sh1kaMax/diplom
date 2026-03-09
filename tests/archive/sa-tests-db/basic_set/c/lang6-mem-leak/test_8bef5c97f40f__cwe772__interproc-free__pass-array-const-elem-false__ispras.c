// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-free.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор освобождается в пользовательской функции.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

void my_fclose(FILE *ptr) { fclose(ptr); }

void func(int param, const char *path) {
  FILE *f = NULL;

  int arr[100];
  arr[31] = !param;
  arr[75] = 7;

  if (param) {
    f = fopen(path, "r"); // FLAW
  }

  param = arr[31];

  if (param) {
    if (f != NULL) {
      my_fclose(f);
    }
  }
}
