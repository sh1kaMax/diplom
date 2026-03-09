// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1852 / (wrapper_par - 15); }

class ExceptionClass {};

void func(void) {
  int divident = 28, divisor = 4, result;

  try {
    result = wrapper(divisor);
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    divisor = 15;
  }
}
