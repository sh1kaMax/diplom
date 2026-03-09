// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int ret_func(int param1) { return param1; }

void func(int param) {
  float divident = 38.24, divisor = 18.87, result;

  int func_res = ret_func(10);

  if (param + func_res > 33) {
    divisor = 0.0;
  }

  if (param + func_res > 33) {
    result = divident / divisor; // FLAW
  }
}
