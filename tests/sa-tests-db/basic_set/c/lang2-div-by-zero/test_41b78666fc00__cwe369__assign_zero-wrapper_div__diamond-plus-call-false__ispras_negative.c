// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1485 / wrapper_par; }

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 29, divisor = 5, result;

  int func_res = ret_func(10);

  if (param + func_res > 32) {
    divisor = 0;
  }

  if (param + func_res < 32) {
    result = wrapper(divisor);
  }
}
