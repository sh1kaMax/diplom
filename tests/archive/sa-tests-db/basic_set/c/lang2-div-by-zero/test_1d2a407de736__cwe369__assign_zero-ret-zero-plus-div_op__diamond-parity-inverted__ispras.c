// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-parity-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// на чётность параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 79; }

void func(int param) {
  int divident = 65, divisor = 7, result;

  if (param % 2 == 0) {
    divisor = wrapper(64);
    divisor -= 79;
  }

  if (param % 2 == 1) {
    result = divident / divisor;
  }
}
