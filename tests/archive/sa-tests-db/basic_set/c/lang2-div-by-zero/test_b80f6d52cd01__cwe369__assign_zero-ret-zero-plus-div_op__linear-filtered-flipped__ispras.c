// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: linear-filtered-flipped.c
// Прямолинейный участок кода от источника до стока с фильтрацией перед
// источником.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 52; }

void func(void) {
  int divident = 35, divisor = 4, result;

  divisor = 4;

  divisor = wrapper(16);
  divisor -= 52;

  result = divident / divisor; // FLAW
}
