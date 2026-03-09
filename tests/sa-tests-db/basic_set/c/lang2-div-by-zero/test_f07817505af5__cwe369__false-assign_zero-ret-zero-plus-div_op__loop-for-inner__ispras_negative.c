// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 73; }

void func(void) {
  int divident = 50, divisor = 5, result;

  int var, var2;

  divisor = wrapper(67);
  divisor -= 66;

  for (var = 0; var < 16; var++) {
    for (var2 = var; var2 < 13; var2++) {
      result = divident / divisor;
    }
  }
}
