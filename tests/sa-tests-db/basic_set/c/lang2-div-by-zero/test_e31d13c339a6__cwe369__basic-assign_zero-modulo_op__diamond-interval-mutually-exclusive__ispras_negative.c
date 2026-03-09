// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 16, divisor = 3, result;

  if (param > 15 && param < 66) {
    divisor = 0;
  }

  if (param <= 15 || param >= 66) {
    result = divident % divisor;
  }
}
