// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  float divident = 30.18, divisor = 27.3, result;

  try {
    result = divident / divisor;
    throw ExceptionClass();
    divisor = 0.0;
  } catch (const ExceptionClass &excpt) {
  }
}
