// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <stdlib.h>

void func(void) {
  int divident = 34, divisor = 7, result;
  int var_a = 105;
  int var_b = 105;

  divisor = var_a - var_b;

  if (!(divisor == 0)) {
    divisor = var_a;
  }

  result = divident / divisor; // FLAW
}
