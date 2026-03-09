// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int divident = 34, divisor = 4, result;
  int var_a = 127;
  int var_b = 127;

  try {
    result = divident / divisor;
    throw ExceptionClass();
    divisor = var_a - var_b;
  } catch (const ExceptionClass &excpt) {
  }
}
