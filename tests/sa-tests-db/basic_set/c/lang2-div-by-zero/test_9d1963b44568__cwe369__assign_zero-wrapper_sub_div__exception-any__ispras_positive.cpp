// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1072 / (wrapper_par - 13); }

class ExceptionClass {};

void func(void) {
  int divident = 34, divisor = 9, result;

  try {
    divisor = 13;
    throw ExceptionClass();
  } catch (...) {
    result = wrapper(divisor); // FLAW
  }
}
