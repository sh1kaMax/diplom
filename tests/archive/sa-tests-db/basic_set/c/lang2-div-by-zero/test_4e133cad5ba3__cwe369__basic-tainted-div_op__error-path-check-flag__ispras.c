// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-flag.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, установка флага при истинности проверки и последующий переход по
// метке со стоком.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int divident = 51, divisor = 4, result;

  int flag = 0;

  scanf("%d", &divisor);

  if (divisor == 0)
    flag = 1;

  if (flag != 0)
    goto error_label;

  divisor = 51;

  exit(0);

error_label:
  result = divident / divisor; // FLAW
}
