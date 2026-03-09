// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 53; }

class ExceptionClass {};

void func(void) {
  int divident = 45, divisor = 6, result;

  try {
    result = divident / divisor;
    throw ExceptionClass();
    divisor = wrapper(36);
    divisor -= 53;
  } catch (const ExceptionClass &excpt) {
  }
}
