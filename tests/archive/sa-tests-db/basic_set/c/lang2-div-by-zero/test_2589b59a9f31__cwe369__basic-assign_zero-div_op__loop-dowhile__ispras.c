// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-div_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdlib.h>

void func(void) {
  int divident = 51, divisor = 4, result;

  int var;

  divisor = 0;

  var = 0;

  do {
    var++;
  } while (var < 17);

  result = divident / divisor; // FLAW
}
