// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 26; }

class ExceptionClass {};

void func(void) {
  int divident = 42, divisor = 4, result;

  try {
    result = divident / divisor;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    divisor = wrapper(46);
    divisor -= 26;
  }
}
