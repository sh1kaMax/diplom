// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 16; }

void func(void) {
  int divident = 26, divisor = 5, result;

  divisor = wrapper(60);
  divisor -= 16;

  if (divisor == 0) {
    divisor = 5;
  } else {
    result = divident / divisor;
  }
}
