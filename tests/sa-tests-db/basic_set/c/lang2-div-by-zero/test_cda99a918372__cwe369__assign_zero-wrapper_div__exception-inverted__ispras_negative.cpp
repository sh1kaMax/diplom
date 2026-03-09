// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1873 / wrapper_par; }

class ExceptionClass {};

void func(void) {
  int divident = 36, divisor = 7, result;

  try {
    result = wrapper(divisor);
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    divisor = 0;
  }
}
