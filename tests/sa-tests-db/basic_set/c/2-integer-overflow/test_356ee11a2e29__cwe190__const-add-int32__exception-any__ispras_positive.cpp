// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int32.json
//
// Знаковое значение задается с помощью константы INT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int32_t data = 0;
  int32_t result;

  try {
    data = INT_MAX;
    throw ExceptionClass();
  } catch (...) {
    result = data + 1; // FLAW
  }
}
