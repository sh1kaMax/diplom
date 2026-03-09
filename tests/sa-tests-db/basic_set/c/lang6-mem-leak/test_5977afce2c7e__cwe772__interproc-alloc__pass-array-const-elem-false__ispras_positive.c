// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-alloc.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор возвращается из пользовательской функции.
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

FILE *my_fopen(const char *my_path) {
  if (my_path != NULL) {
    return fopen(my_path, "r");
  } else {
    return NULL;
  }
}

void func(int param, const char *path) {
  FILE *f = NULL;

  int arr[100];
  arr[1] = !param;
  arr[66] = 7;

  if (param) {
    f = my_fopen(path); // FLAW
  }

  param = arr[1];

  if (param) {
    if (f != NULL) {
      fclose(f);
    }
  }
}
