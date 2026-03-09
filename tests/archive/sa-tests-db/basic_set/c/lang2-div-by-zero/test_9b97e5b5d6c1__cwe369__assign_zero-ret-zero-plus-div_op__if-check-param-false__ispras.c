// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 63; }

void func(int param) {
  int divident = 52, divisor = 3, result;

  divisor = wrapper(61);
  divisor -= 63;

  if (param > 19 && param < 20) {
    result = divident / divisor;
  }
}
