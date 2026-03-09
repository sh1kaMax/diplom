// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-modulo_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции взятия остатка от
// деления).
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdlib.h>

void func(void) {
  int divident = 46, divisor = 7, result;

  int flag = 0;

  divisor = 0;

  if (divisor == 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  divisor = 7;

  exit(0);

error_label:
  result = divident % divisor; // FLAW
}
