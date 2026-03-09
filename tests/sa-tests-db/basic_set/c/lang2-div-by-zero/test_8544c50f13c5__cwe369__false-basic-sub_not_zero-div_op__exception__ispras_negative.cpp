// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int divident = 52, divisor = 6, result;
  int var_a = 150;
  int var_b = 156;

  try {
    result = divident / divisor;
    throw ExceptionClass();
    divisor = var_a - var_b;
  } catch (const ExceptionClass &excpt) {
  }
}
