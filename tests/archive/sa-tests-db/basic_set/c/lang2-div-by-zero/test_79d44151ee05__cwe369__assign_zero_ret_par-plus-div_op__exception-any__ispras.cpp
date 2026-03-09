// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: exception-any.cpp
// Тест с try-catch, где источник находится в try-части, а приёмник в catch. В
// теле try кидается исключение.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

class ExceptionClass {};

void func(void) {
  int divident = 33, divisor = 8, result;

  try {
    divisor = wrapper(17);
    divisor -= 17;
    throw ExceptionClass();
  } catch (...) {
    result = divident / divisor; // FLAW
  }
}
