// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

void func(void) {
  int divident = 50, divisor = 9, result;
  int var_a = 144;
  int var_b = 145;

  int flag = 0;

  divisor = var_a - var_b;

  if (divisor == 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  divisor = var_a;

  exit(0);

error_label:
  result = divident / divisor;
}
