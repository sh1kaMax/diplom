// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int divident = 51, divisor = 3, result;
  int var_a = 28;
  int var_b = 28;

  try {
    divisor = var_a - var_b;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = divident / divisor; // FLAW
  }
}
