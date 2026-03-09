// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// простых условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 32, divisor = 9, result;
  int var_a = 126;
  int var_b = 129;

  if (param > 41) {
    divisor = var_a - var_b;
  }

  if (param <= 41) {
    result = divident / divisor;
  }
}
