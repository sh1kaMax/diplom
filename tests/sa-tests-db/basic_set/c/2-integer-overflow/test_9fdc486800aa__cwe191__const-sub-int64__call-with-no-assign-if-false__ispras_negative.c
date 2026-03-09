// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-int64.json
//
// Знаковое значение задается с помощью константы LLONG_MIN.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
//
// Поточный вариант: call-with-no-assign-if-false.c
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
    *pointer_param = 83;
}

void func(void) {
  int64_t data = 1;
  int64_t result;

  int var = 0;

  data = LLONG_MIN;

  callee(&var, -7);

  if (var < 572) {
    exit(0);
  }

  result = data - 1;
}
