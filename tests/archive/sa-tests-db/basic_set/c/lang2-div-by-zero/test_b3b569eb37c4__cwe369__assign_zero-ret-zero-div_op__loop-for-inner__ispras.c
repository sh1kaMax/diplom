// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(void) {
  int divident = 15, divisor = 3, result;

  int var, var2;

  divisor = wrapper(41);

  for (var = 0; var < 20; var++) {
    for (var2 = var; var2 < 10; var2++) {
      result = divident / divisor; // FLAW
    }
  }
}
