// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(void) {
  int divident = 46, divisor = 6, result;

  divisor = wrapper(55);

  if (divisor == 0) {
    divisor = 6;
  } else {
    result = divident / divisor;
  }
}
