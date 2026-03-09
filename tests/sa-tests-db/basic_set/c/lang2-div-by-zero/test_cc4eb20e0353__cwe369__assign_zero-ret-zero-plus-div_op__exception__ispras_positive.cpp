// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 16; }

class ExceptionClass {};

void func(void) {
  int divident = 40, divisor = 5, result;

  try {
    divisor = wrapper(34);
    divisor -= 16;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = divident / divisor; // FLAW
  }
}
