// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(int param) {
  int divident = 53, divisor = 10, result;

  if (param > 48 && param < 67) {
    divisor = wrapper(46);
  }

  if (param > 48 && param < 67) {
    result = divident / divisor; // FLAW
  }
}
