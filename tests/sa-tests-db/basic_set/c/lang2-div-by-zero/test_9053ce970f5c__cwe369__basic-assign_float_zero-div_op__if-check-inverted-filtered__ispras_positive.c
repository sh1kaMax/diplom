// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <stdlib.h>

void func(void) {
  float divident = 24.54, divisor = 46.77, result;

  divisor = 0.0;

  if (!(divisor == 0.0)) {
    divisor = 7.34;
  }

  result = divident / divisor; // FLAW
}
