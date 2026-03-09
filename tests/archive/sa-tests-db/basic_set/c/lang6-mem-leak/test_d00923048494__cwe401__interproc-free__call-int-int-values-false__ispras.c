// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-free.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память освобождается в пользовательской функции.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdio.h>
#include <stdlib.h>

void my_free(void *ptr) { free(ptr); }

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

void func(size_t size) {
  void *f = NULL;

  int local_var = 54;

  f = malloc(size);

  if (callee(local_var, 89) > 0) {
    exit(0);
  }

  if (f != NULL) {
    my_free(f);
  }
}
