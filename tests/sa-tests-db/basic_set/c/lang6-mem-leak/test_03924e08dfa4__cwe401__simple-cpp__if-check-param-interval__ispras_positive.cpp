// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: simple-cpp.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом delete.
//
// Поточный вариант: if-check-param-interval.cpp
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void func(int param, size_t size) {
  int *f = NULL;

  f = new int[size]; // FLAW

  if (param > 35 && param < 70) {
    delete[] f;
  }
}
