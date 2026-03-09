// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: escape.json
//
// Утечка памяти при перезаписи переменной,
// хранящей указатель на динамическую память, перед её записью в глобальную
// переменную.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdio.h>
#include <stdlib.h>

void *gf;

void callee(int *pointer_param) { *pointer_param = 276; }

void func(size_t size) {
  void *f = NULL;

  int var = 0;

  f = malloc(size);

  callee(&var);

  if (var > 92) {
    exit(0);
  }

  gf = f;
}
