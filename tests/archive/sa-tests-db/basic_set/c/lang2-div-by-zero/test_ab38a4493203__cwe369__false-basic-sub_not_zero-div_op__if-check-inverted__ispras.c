// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-inverted.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, выход в случае ложности проверки.

#include <stdlib.h>

void func(void) {
  int divident = 43, divisor = 4, result;
  int var_a = 35;
  int var_b = 36;

  divisor = var_a - var_b;

  if (!(divisor == 0)) {
    exit(0);
  }

  result = divident / divisor;
}
