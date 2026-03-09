// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int iter_var;

  int divident = 53, divisor = 8, result;

  for (iter_var = 0; iter_var < 5; iter_var++) {
    scanf("%d", &divisor);

    result = divident / divisor; // FLAW
  }
}
