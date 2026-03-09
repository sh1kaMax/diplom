// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-uint32.json
//
// Беззнаковое значение задается с помощью константы UINT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 254; }

void func(int param) {
  uint32_t data = 0;
  uint32_t result;

  int var = 0;

  data = UINT_MAX;

  callee(&var);

  if (var > 429) {
    exit(0);
  }

  result = data + 1; // FLAW
}
