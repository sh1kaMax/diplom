// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 13; }

class ExceptionClass {};

void func(void) {
  int divident = 55, divisor = 9, result;

  try {
    divisor = 0;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = wrapper(divisor);
  }
}
