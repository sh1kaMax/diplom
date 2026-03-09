// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 77; }

void func(void) {
  int divident = 56, divisor = 8, result;

  int var;

  divisor = wrapper(16);
  divisor -= 69;

  var = 0;

  for (var = 0; var < 18; var++)
    ;

  result = divident / divisor;
}
