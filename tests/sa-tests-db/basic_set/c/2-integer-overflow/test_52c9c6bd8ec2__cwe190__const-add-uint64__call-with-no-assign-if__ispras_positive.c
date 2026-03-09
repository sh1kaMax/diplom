// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint64.json
//
// Беззнаковое значение задается с помощью константы ULLONG_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: call-with-no-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 60;
}

void func(void) {
  uint64_t data = 0;
  uint64_t result;

  int var = 0;

  data = ULLONG_MAX;

  callee(&var, -8);

  if (var > 431) {
    exit(0);
  }

  result = data + 1; // FLAW
}
