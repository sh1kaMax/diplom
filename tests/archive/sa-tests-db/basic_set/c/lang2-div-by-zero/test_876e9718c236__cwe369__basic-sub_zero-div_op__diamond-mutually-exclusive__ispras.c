// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// простых условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 26, divisor = 9, result;
  int var_a = 71;
  int var_b = 71;

  if (param > 11) {
    divisor = var_a - var_b;
  }

  if (param <= 11) {
    result = divident / divisor;
  }
}
