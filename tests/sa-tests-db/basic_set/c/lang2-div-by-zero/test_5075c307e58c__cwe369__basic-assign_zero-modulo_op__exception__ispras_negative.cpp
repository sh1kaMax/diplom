// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int divident = 20, divisor = 9, result;

  try {
    result = divident % divisor;
    throw ExceptionClass();
    divisor = 0;
  } catch (const ExceptionClass &excpt) {
  }
}
