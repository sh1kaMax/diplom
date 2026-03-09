// Авторы теста: ИСП РАН
// CWE: 772
// Название: Missing Release of Resource after Effective Lifetime
// Модельный вариант: interproc-alloc-by-ref.json
//
// Утечка файлового дескриптора при выходе из области видимости переменной,
// хранящей открытый дескриптор, или перезаписи переменной перед вызовом
// fclose(). Дескриптор выделяется в пользовательской функции по указателю.
//
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

void my_fopen(FILE **ptr, const char *my_path) {
  if (ptr != NULL) {
    *ptr = fopen(my_path, "r");
  }
}

void func(const char *path) {
  FILE *f = NULL;

  my_fopen(&f, path); // FLAW

  if (f != NULL) {
    f = NULL;
  }

  if (f != NULL) {
    fclose(f);
  }
}
