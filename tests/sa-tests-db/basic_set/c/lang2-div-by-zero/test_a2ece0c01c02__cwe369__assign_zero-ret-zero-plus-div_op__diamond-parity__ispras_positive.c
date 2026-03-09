// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-parity.c
// Достижимый путь от источника до стока с проверками одного и того же условия
// на чётность параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 82; }

void func(int param) {
  int divident = 66, divisor = 3, result;

  if (param % 2) {
    divisor = wrapper(54);
    divisor -= 82;
  }

  if (param % 2) {
    result = divident / divisor; // FLAW
  }
}
