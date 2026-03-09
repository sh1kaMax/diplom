// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: exception-inverted.cpp
// Тест с try-catch, где приёмник находится в try-части, а источник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

class ExceptionClass {};

void func(void) {
  int divident = 46, divisor = 9, result;

  try {
    result = divident / divisor;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    divisor = wrapper(33);
    divisor -= 33;
  }
}
