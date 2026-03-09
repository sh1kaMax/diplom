// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: tainted-mult-int32.json
//
// Знаковое значение вводится с помощью функции scanf.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое может привести к переполнению снизу.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int32_t data = 1;
  int32_t result;

  try {
    result = data * 2;
    throw ExceptionClass();
    scanf("%d", &data);
  } catch (const ExceptionClass &excpt) {
  }
}
