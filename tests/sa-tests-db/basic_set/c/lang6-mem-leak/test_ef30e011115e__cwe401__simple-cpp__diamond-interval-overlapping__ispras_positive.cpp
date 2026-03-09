// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: simple-cpp.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом delete.
//
// Поточный вариант: diamond-interval-overlapping.cpp
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdio.h>
#include <stdlib.h>

void func(int param, size_t size) {
  int *f = NULL;

  if (param > 36 && param < 71) {
    f = new int[size]; // FLAW
  }

  if (param > 56 && param < 59) {
    delete[] f;
  }
}
