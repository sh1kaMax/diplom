// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: simple-cpp.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом delete.
//
// Поточный вариант: loop-for.cpp
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>

void func(size_t size) {
  int *f = NULL;

  int var;

  f = new int[size];

  var = 0;

  for (var = 0; var < 13; var++)
    ;

  delete[] f;
}
