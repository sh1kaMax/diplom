// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check-inverted-filtered.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

void func(void) {
  float divident = 68.67, divisor = 14.34, result;

  divisor = 0.0;

  if (!(divisor == 0.0)) {
    divisor = 51.35;
  } else {
    result = divident / divisor; // FLAW
  }
}
