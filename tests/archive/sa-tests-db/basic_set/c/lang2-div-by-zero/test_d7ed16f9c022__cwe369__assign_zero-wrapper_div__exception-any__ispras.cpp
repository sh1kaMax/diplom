// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1958 / wrapper_par; }

class ExceptionClass {};

void func(void) {
  int divident = 26, divisor = 8, result;

  try {
    divisor = 0;
    throw ExceptionClass();
  } catch (...) {
    result = wrapper(divisor); // FLAW
  }
}
