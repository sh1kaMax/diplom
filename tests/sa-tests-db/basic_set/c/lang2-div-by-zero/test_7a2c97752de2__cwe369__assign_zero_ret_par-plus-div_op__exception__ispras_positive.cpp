// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
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
  int divident = 28, divisor = 5, result;

  try {
    divisor = wrapper(56);
    divisor -= 56;
    throw ExceptionClass();
  } catch (const ExceptionClass &excpt) {
    result = divident / divisor; // FLAW
  }
}
