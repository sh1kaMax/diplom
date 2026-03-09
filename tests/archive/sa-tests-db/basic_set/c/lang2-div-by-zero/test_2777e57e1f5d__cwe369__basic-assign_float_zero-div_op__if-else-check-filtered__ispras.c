// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости.

#include <stdlib.h>

void func(void) {
  float divident = 16.35, divisor = 16.16, result;

  divisor = 0.0;

  if (divisor == 0.0) {
    divisor = -57.96;
  } else {
    result = divident / divisor;
  }
}
