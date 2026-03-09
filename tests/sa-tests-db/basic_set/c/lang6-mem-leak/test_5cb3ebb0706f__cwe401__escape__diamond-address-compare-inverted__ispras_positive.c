// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её записью в глобальную
// переменную.
//
// Поточный вариант: diamond-address-compare-inverted.c
// Недостижимый путь от источника до стока с проверками похожих условий, которые
// сравнивают адреса полей.

#include <stdio.h>
#include <stdlib.h>

void *gf;

struct struct_type {
  int field1;
  int field2;
  int field3;
};

struct struct_type struct_glob;

void func(size_t size) {
  void *f = NULL;

  int *addr1 = &struct_glob.field1;
  int *addr2 = &struct_glob.field2;

  if (addr2 > addr1) {
    f = malloc(size); // FLAW
  }

  if (addr2 < addr1) {
    gf = f;
  }
}
