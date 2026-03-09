// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-no-free.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память передается в пользовательскую функцию,
// которая не освобождает её.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>

void no_free(void *ptr) {
  if (ptr == NULL) {
    free(ptr);
  }
}

void callee(int *pointer_param) { *pointer_param = 375; }

void func(size_t size) {
  void *f = NULL;

  int var = 0;

  f = malloc(size); // FLAW

  callee(&var);

  if (var > 750) {
    exit(0);
  }

  if (f != NULL) {
    no_free(f);
  }
}
