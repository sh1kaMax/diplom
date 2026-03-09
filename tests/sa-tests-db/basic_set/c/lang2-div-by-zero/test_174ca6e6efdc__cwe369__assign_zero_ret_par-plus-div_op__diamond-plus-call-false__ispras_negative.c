// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 29, divisor = 6, result;

  int func_res = ret_func(10);

  if (param + func_res > 18) {
    divisor = wrapper(16);
    divisor -= 16;
  }

  if (param + func_res < 18) {
    result = divident / divisor;
  }
}
