// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-free.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память освобождается в пользовательской функции.
//
// Поточный вариант: switch-default.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; сток расположен в невыполняемой ветке default оператора
// выбора.

#include <stdio.h>
#include <stdlib.h>

void my_free(void *ptr) { free(ptr); }

void func(size_t size) {
  void *f = NULL;

  int var;

  f = malloc(size);

  var = 0;

  switch (var) {
  case 0:
    exit(0);
    break;
  default:
    if (f != NULL) {
      my_free(f);
    }
    break;
  }
}
