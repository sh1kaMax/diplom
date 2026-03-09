// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 28, divisor = 3, result;
  int var_a = 70;
  int var_b = 70;

  if (param > 29 && param < 56) {
    divisor = var_a - var_b;
  }

  if (param <= 29 || param >= 56) {
    result = divident / divisor;
  }
}
