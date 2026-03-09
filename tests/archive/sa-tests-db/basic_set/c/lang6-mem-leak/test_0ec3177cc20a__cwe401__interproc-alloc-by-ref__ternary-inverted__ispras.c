// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: interproc-alloc-by-ref.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free(). Память выделяется в пользовательской функции по указателю.
//
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

void my_malloc(void **ptr, size_t my_size) {
  if (ptr != NULL) {
    *ptr = malloc(my_size);
  }
}

void func(size_t size) {
  void *f = NULL;

  int var;

  my_malloc(&f, size); // FLAW

  var = (f != NULL ? 0 : 1);

  if (var) {
    if (f != NULL) {
      free(f);
    }
  }
}
