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
// Тест с try-catch, где источник находится после того, как кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1149 / wrapper_par1;
}

class ExceptionClass {};

void func(void) {
  int divident = 56, divisor = 3, result;

  try {
    result = wrapper(divisor, divident);
    throw ExceptionClass();
    divisor = 0;
  } catch (const ExceptionClass &excpt) {
  }
}
