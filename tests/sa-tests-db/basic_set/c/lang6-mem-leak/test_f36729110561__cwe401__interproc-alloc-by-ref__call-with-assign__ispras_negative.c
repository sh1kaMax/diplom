// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-alloc-by-ref.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Память выделяется в пользовательской функции по указателю.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>

void my_malloc(void **ptr, size_t my_size) {
  if (ptr != NULL) {
    *ptr = malloc(my_size);
  }
}

void callee(int *pointer_param) { *pointer_param = 109; }

void func(size_t size) {
  void *f = NULL;

  int var = 0;

  my_malloc(&f, size);

  callee(&var);

  if (var > 939) {
    exit(0);
  }

  if (f != NULL) {
    free(f);
  }
}
