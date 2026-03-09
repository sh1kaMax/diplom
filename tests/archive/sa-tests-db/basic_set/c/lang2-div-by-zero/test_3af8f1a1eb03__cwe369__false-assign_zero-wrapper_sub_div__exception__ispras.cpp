// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1037 / (wrapper_par - 13); }

class ExceptionClass {};

void func(void) {
  int divident = 48, divisor = 7, result;

  try {
    divisor = 25;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = wrapper(divisor);
  }
}
