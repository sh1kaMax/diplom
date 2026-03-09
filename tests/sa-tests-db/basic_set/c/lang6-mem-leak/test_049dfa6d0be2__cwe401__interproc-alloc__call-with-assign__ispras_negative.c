// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-alloc.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память возвращается из пользовательской функции.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t my_size) {
  if (my_size > 0) {
    return malloc(my_size);
  } else {
    return NULL;
  }
}

void callee(int *pointer_param) { *pointer_param = 105; }

void func(size_t size) {
  void *f = NULL;

  int var = 0;

  f = my_malloc(size);

  callee(&var);

  if (var > 297) {
    exit(0);
  }

  if (f != NULL) {
    free(f);
  }
}
