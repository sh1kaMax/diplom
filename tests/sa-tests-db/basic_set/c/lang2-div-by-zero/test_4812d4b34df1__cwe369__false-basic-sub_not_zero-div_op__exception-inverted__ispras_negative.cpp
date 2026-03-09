// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int divident = 24, divisor = 9, result;
  int var_a = 90;
  int var_b = 99;

  try {
    result = divident / divisor;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    divisor = var_a - var_b;
  }
}
