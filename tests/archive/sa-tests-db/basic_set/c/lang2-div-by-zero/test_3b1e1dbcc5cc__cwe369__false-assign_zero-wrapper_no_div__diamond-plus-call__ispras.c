// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 12; }

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 67, divisor = 9, result;

  int func_res = ret_func(10);

  if (param + func_res > 31) {
    divisor = 0;
  }

  if (param + func_res > 31) {
    result = wrapper(divisor);
  }
}
