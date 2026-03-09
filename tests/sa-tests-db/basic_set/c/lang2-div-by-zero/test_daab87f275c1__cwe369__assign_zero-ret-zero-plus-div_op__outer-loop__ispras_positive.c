// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 81; }

void func(void) {
  int iter_var;

  int divident = 25, divisor = 3, result;

  for (iter_var = 6; iter_var < 32; iter_var++) {
    divisor = wrapper(52);
    divisor -= 81;

    result = divident / divisor; // FLAW
  }
}
