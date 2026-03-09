// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1434 / wrapper_par1;
}

class ExceptionClass {};

void func(void) {
  int divident = 23, divisor = 9, result;

  try {
    divisor = 0;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = wrapper(divisor, divident); // FLAW
  }
}
