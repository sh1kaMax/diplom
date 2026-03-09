// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

class ExceptionClass {};

void func(void) {
  int divident = 53, divisor = 3, result;

  try {
    result = divident / divisor;
    throw ExceptionClass();
    divisor = wrapper(55);
  } catch (const ExceptionClass &excpt) {
  }
}
