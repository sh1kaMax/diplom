// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int64.json
//
// Знаковое значение задается с помощью константы LLONG_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int64_t data = 0;
  int64_t result;

  result = data + 1;

  data = LLONG_MAX;
}
