// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free().
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdio.h>
#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 241; }

void func(size_t size) {
  void *f = NULL;

  int var = 0;

  f = malloc(size);

  callee(&var);

  if (var > 108) {
    exit(0);
  }

  if (f != NULL) {
    free(f);
  }
}
