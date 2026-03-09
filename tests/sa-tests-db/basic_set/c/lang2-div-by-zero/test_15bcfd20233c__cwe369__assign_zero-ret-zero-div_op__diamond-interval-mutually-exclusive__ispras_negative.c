// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(int param) {
  int divident = 32, divisor = 4, result;

  if (param > 10 && param < 24) {
    divisor = wrapper(31);
  }

  if (param <= 10 || param >= 24) {
    result = divident / divisor;
  }
}
