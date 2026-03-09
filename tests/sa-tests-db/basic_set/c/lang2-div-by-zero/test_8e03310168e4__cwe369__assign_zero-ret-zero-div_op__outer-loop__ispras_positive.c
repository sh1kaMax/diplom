// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(void) {
  int iter_var;

  int divident = 50, divisor = 8, result;

  for (iter_var = 3; iter_var < 10; iter_var++) {
    divisor = wrapper(42);

    result = divident / divisor; // FLAW
  }
}
