// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-int64.json
//
// Знаковое значение задается с помощью константы LLONG_MIN.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int64_t data = 1;
  int64_t result;

  try {
    result = data - 1;
    throw ExceptionClass();
    data = LLONG_MIN;
  } catch (const ExceptionClass &excpt) {
  }
}
