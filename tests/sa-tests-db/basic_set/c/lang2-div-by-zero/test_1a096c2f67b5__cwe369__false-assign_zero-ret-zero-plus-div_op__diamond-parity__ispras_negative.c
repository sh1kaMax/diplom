// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 33; }

void func(int param) {
  int divident = 37, divisor = 4, result;

  if (param % 2) {
    divisor = wrapper(36);
    divisor -= 31;
  }

  if (param % 2) {
    result = divident / divisor;
  }
}
