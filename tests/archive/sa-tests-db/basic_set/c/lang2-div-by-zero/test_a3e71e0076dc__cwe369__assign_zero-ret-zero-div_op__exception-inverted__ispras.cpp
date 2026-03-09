// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

class ExceptionClass {};

void func(void) {
  int divident = 58, divisor = 8, result;

  try {
    result = divident / divisor;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    divisor = wrapper(53);
  }
}
