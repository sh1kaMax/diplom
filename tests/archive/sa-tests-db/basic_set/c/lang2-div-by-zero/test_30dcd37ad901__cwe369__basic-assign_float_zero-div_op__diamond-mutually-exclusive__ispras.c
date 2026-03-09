// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// простых условий, результат которых зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  float divident = 26.98, divisor = 47.22, result;

  if (param > 16) {
    divisor = 0.0;
  }

  if (param <= 16) {
    result = divident / divisor;
  }
}
