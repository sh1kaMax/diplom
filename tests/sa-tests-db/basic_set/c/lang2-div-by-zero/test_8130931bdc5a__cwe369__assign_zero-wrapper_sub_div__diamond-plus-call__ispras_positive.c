// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1319 / (wrapper_par - 17); }

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 52, divisor = 6, result;

  int func_res = ret_func(10);

  if (param + func_res > 43) {
    divisor = 17;
  }

  if (param + func_res > 43) {
    result = wrapper(divisor); // FLAW
  }
}
