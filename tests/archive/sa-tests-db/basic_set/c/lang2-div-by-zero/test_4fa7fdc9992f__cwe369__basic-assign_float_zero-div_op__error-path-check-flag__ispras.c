// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

void func(void) {
  float divident = 25.48, divisor = 19.61, result;

  int flag = 0;

  divisor = 0.0;

  if (divisor == 0.0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  divisor = 90.76;

  exit(0);

error_label:
  result = divident / divisor; // FLAW
}
