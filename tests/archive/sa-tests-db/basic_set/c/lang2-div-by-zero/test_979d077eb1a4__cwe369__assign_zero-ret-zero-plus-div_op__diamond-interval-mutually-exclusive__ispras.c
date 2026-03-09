// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 88; }

void func(int param) {
  int divident = 47, divisor = 4, result;

  if (param > 37 && param < 48) {
    divisor = wrapper(18);
    divisor -= 88;
  }

  if (param <= 37 || param >= 48) {
    result = divident / divisor;
  }
}
