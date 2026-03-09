// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: const-add-int32.json
//
// Знаковое значение задается с помощью константы INT_MAX.
// Данное значение без проверки используется в качестве слагаемого для
// вычисления, которое приводит к переполнению.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int32_t data = 0;
  int32_t result;

  try {
    result = data + 1;
    throw ExceptionClass();
    data = INT_MAX;
  } catch (const ExceptionClass &excpt) {
  }
}
