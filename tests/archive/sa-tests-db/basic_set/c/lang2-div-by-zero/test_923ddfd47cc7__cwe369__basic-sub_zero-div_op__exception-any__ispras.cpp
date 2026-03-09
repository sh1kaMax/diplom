// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

class ExceptionClass {};

void func(void) {
  int divident = 66, divisor = 6, result;
  int var_a = 81;
  int var_b = 81;

  try {
    divisor = var_a - var_b;
    throw ExceptionClass();
  } catch (...) {
    result = divident / divisor; // FLAW
  }
}
