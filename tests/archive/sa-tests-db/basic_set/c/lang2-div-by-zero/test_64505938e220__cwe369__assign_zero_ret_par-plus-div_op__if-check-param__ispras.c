// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(int param) {
  int divident = 17, divisor = 7, result;

  divisor = wrapper(53);
  divisor -= 53;

  if (param > 45) {
    result = divident / divisor; // FLAW
  }
}
