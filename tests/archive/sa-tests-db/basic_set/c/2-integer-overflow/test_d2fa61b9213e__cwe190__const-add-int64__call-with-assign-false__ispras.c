// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int64.json
//
// Знаковое значение задается с помощью константы LLONG_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 391; }

void func(int param) {
  int64_t data = 0;
  int64_t result;

  int var = 0;

  data = LLONG_MAX;

  callee(&var);

  if (var > 31) {
    exit(0);
  }

  result = data + 1;
}
