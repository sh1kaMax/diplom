// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond.c
// Достижимый путь от источника до стока с проверками одного и того же простого
// условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 32; }

void func(int param) {
  int divident = 23, divisor = 4, result;

  if (param > 21) {
    divisor = wrapper(51);
    divisor -= 27;
  }

  if (param > 21) {
    result = divident / divisor;
  }
}
