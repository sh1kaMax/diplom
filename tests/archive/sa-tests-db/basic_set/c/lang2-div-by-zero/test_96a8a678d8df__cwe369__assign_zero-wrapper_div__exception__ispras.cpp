// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1479 / wrapper_par; }

class ExceptionClass {};

void func(void) {
  int divident = 60, divisor = 4, result;

  try {
    result = wrapper(divisor);
    throw ExceptionClass();
    divisor = 0;
  } catch (const ExceptionClass &excpt) {
  }
}
