// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: error-path-check-filtered.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, фильтрация и переход по метке в случае истинности
// проверки.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int divident = 48, divisor = 3, result;

  scanf("%d", &divisor);

  if (divisor == 0) {

    divisor = 48;

    goto error_label;
  }

  exit(0);

error_label:
  result = divident / divisor;
}
