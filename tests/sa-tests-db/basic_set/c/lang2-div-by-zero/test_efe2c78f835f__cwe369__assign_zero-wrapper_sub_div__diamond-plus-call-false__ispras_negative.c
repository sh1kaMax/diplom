// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1673 / (wrapper_par - 16); }

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 31, divisor = 7, result;

  int func_res = ret_func(10);

  if (param + func_res > 26) {
    divisor = 16;
  }

  if (param + func_res < 26) {
    result = wrapper(divisor);
  }
}
