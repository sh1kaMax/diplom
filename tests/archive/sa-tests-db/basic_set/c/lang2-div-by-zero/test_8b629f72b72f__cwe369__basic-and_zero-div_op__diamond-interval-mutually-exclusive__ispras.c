// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-and_zero-div_op.json
//
// Нулевое значение получается как результат побитового и.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 21, divisor = 10, result;
  int var_a = 0;

  if (param > 5 && param < 31) {
    divisor = param & var_a;
  }

  if (param <= 5 || param >= 31) {
    result = divident / divisor;
  }
}
