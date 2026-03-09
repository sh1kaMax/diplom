// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 44; }

class ExceptionClass {};

void func(void) {
  int divident = 70, divisor = 8, result;

  try {
    divisor = wrapper(53);
    divisor -= 37;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = divident / divisor;
  }
}
