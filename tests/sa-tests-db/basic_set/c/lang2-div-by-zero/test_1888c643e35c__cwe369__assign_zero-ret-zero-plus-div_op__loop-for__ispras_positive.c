// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 32; }

void func(void) {
  int divident = 22, divisor = 7, result;

  int var;

  divisor = wrapper(58);
  divisor -= 32;

  var = 0;

  for (var = 0; var < 20; var++)
    ;

  result = divident / divisor; // FLAW
}
