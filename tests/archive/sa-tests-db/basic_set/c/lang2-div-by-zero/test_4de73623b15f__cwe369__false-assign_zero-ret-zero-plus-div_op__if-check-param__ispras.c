// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 41; }

void func(int param) {
  int divident = 22, divisor = 10, result;

  divisor = wrapper(40);
  divisor -= 31;

  if (param > 40) {
    result = divident / divisor;
  }
}
