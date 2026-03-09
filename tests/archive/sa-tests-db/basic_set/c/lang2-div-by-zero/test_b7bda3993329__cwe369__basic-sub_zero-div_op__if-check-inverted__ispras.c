// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-inverted.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, выход в случае ложности проверки.

#include <stdlib.h>

void func(void) {
  int divident = 43, divisor = 3, result;
  int var_a = 55;
  int var_b = 55;

  divisor = var_a - var_b;

  if (!(divisor == 0)) {
    exit(0);
  }

  result = divident / divisor; // FLAW
}
