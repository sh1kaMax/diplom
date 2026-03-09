// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1262 / (wrapper_par - 15); }

class ExceptionClass {};

void func(void) {
  int divident = 59, divisor = 4, result;

  try {
    result = wrapper(divisor);
    throw ExceptionClass();
    divisor = 15;
  } catch (const ExceptionClass &excpt) {
  }
}
