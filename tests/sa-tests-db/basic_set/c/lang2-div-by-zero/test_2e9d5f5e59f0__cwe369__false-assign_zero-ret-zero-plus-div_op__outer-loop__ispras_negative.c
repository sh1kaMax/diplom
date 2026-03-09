// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 21; }

void func(void) {
  int iter_var;

  int divident = 49, divisor = 8, result;

  for (iter_var = 5; iter_var < 23; iter_var++) {
    divisor = wrapper(44);
    divisor -= 13;

    result = divident / divisor;
  }
}
