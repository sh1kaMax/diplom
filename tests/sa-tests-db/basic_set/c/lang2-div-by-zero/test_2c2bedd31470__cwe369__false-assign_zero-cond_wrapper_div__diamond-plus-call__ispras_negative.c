// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1057 / wrapper_par1;
}

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 63, divisor = 9, result;

  int func_res = ret_func(10);

  if (param + func_res > 37) {
    divisor = 0;
  }

  if (param + func_res > 37) {
    result = wrapper(divisor, -divident);
  }
}
