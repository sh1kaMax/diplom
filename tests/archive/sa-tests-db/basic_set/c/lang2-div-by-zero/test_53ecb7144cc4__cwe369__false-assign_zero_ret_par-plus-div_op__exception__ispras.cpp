// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero_ret_par-plus-div_op.json
//
// Ненулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: exception.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

class ExceptionClass {};

void func(void) {
  int divident = 24, divisor = 4, result;

  try {
    divisor = wrapper(21);
    divisor -= 13;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = divident / divisor;
  }
}
