// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1765 / (wrapper_par - 19); }

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 27, divisor = 5, result;

  int func_res = ret_func(10);

  if (param + func_res > 45) {
    divisor = 32;
  }

  if (param + func_res > 45) {
    result = wrapper(divisor);
  }
}
