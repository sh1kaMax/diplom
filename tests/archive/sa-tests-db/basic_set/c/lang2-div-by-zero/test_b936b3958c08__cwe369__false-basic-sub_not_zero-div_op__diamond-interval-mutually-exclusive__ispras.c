// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 40, divisor = 4, result;
  int var_a = 121;
  int var_b = 126;

  if (param > 8 && param < 30) {
    divisor = var_a - var_b;
  }

  if (param <= 8 || param >= 30) {
    result = divident / divisor;
  }
}
