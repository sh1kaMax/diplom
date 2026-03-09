// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки.

#include <stdlib.h>

void func(void) {
  int divident = 15, divisor = 6, result;
  int var_a = 167;
  int var_b = 170;

  divisor = var_a - var_b;

  if (divisor == 0) {
    divisor = var_a;
  }

  result = divident / divisor;
}
