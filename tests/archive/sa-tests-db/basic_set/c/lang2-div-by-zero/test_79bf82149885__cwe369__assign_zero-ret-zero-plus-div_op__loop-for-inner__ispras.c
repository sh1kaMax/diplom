// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 38; }

void func(void) {
  int divident = 51, divisor = 5, result;

  int var, var2;

  divisor = wrapper(23);
  divisor -= 38;

  for (var = 0; var < 20; var++) {
    for (var2 = var; var2 < 19; var2++) {
      result = divident / divisor; // FLAW
    }
  }
}
