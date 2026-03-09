// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-alloc.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Выделенная память возвращается из пользовательской функции.
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t my_size) {
  if (my_size > 0) {
    return malloc(my_size);
  } else {
    return NULL;
  }
}

void func(size_t size) {
  void *f = NULL;

  int flag = 0;

  f = my_malloc(size);

  if (f != NULL)
    flag = 1;

  if (flag != 0)
    goto error_label;

  f = NULL;

  exit(0);

error_label:
  if (f != NULL) {
    free(f);
  }
}
