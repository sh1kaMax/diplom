// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1347 / (wrapper_par - 12); }

class ExceptionClass {};

void func(void) {
  int divident = 32, divisor = 7, result;

  try {
    divisor = 25;
    throw ExceptionClass();
  } catch (...) {
    result = wrapper(divisor);
  }
}
