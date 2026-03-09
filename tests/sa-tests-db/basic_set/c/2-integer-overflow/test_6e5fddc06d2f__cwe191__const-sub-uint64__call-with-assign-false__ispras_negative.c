// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-uint64.json
//
// Беззнаковое значение задается с помощью константы 0.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 198; }

void func(void) {
  uint64_t data = 1;
  uint64_t result;

  int var = 0;

  data = 0;

  callee(&var);

  if (var > 146) {
    exit(0);
  }

  result = data - 1;
}
