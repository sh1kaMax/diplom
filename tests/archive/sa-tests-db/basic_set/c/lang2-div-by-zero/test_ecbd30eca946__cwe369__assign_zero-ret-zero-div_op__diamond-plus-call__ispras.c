// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 65, divisor = 9, result;

  int func_res = ret_func(10);

  if (param + func_res > 50) {
    divisor = wrapper(56);
  }

  if (param + func_res > 50) {
    result = divident / divisor; // FLAW
  }
}
