// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: linear-filtered-inverted.c
// Прямолинейный участок кода от источника до стока с фильтрацией после стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 59; }

void func(void) {
  int divident = 69, divisor = 3, result;

  divisor = wrapper(41);
  divisor -= 59;

  result = divident / divisor; // FLAW

  divisor = 3;
}
