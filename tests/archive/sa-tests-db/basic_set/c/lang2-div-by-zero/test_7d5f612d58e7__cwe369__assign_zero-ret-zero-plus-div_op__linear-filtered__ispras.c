// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1; }

void func(void) {
  int divident = 43, divisor = 4, result;

  divisor = wrapper(33);
  divisor -= 1;

  divisor = 4;

  result = divident / divisor;
}
