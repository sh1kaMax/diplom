// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int divident = 18, divisor = 7, result;
  int var_a = 116;
  int var_b = 116;

  try {
    result = divident / divisor;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    divisor = var_a - var_b;
  }
}
