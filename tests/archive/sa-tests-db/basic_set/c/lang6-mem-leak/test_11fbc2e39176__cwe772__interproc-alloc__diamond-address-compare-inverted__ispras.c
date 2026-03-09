// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-alloc.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор возвращается из пользовательской функции.
//
// Поточный вариант: diamond-address-compare-inverted.c
// Недостижимый путь от источника до стока с проверками похожих условий, которые
// сравнивают адреса полей.

#include <stdio.h>
#include <stdlib.h>

FILE *my_fopen(const char *my_path) {
  if (my_path != NULL) {
    return fopen(my_path, "r");
  } else {
    return NULL;
  }
}

struct struct_type {
  int field1;
  int field2;
  int field3;
};

struct struct_type struct_glob;

void func(const char *path) {
  FILE *f = NULL;

  int *addr1 = &struct_glob.field1;
  int *addr2 = &struct_glob.field2;

  if (addr2 > addr1) {
    f = my_fopen(path); // FLAW
  }

  if (addr2 < addr1) {
    if (f != NULL) {
      fclose(f);
    }
  }
}
