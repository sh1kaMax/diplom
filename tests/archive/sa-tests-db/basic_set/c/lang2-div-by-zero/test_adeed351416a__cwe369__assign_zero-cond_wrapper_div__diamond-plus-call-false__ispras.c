// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1533 / wrapper_par1;
}

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 62, divisor = 3, result;

  int func_res = ret_func(10);

  if (param + func_res > 20) {
    divisor = 0;
  }

  if (param + func_res < 20) {
    result = wrapper(divisor, divident);
  }
}
