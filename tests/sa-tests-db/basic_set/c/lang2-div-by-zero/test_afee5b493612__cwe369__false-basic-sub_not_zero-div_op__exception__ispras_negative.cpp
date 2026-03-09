// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int divident = 54, divisor = 5, result;
  int var_a = 18;
  int var_b = 23;

  try {
    divisor = var_a - var_b;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = divident / divisor;
  }
}
