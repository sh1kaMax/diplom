// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int divident = 54, divisor = 6, result;

  scanf("%d", &divisor);

  if (divisor == 0) {
    divisor = 54;
  } else {
    result = divident / divisor;
  }
}
