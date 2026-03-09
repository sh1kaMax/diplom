// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 48; }

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 56, divisor = 4, result;

  int func_res = ret_func(10);

  if (param + func_res > 4) {
    divisor = wrapper(40);
    divisor -= 48;
  }

  if (param + func_res < 4) {
    result = divident / divisor;
  }
}
