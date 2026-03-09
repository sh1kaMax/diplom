// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: simple-cpp.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом delete.
//
// Поточный вариант: linear-inverted.cpp
// Прямолинейный участок кода с источником после стока.

#include <stdio.h>
#include <stdlib.h>

void func(size_t size) {
  int *f = NULL;

  delete[] f;

  f = new int[size]; // FLAW
}
