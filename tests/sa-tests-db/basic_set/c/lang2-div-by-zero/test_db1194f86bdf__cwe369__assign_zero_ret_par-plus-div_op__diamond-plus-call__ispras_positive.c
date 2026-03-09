// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-plus-call.c
// Достижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

int ret_func(int param1) { return param1; }

void func(int param) {
  int divident = 63, divisor = 7, result;

  int func_res = ret_func(10);

  if (param + func_res > 38) {
    divisor = wrapper(67);
    divisor -= 67;
  }

  if (param + func_res > 38) {
    result = divident / divisor; // FLAW
  }
}
