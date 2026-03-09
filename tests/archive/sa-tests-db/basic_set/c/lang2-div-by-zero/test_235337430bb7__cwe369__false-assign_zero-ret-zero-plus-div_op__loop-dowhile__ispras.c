// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 91; }

void func(void) {
  int divident = 49, divisor = 6, result;

  int var;

  divisor = wrapper(49);
  divisor -= 82;

  var = 0;

  do {
    var++;
  } while (var < 18);

  result = divident / divisor;
}
