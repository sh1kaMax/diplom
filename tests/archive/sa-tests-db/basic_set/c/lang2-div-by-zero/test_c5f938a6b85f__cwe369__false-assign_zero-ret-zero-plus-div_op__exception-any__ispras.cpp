// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 43; }

class ExceptionClass {};

void func(void) {
  int divident = 55, divisor = 5, result;

  try {
    divisor = wrapper(20);
    divisor -= 39;
    throw ExceptionClass();
  } catch (...) {
    result = divident / divisor;
  }
}
