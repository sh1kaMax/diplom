// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for-inner.c
// Участок кода от источника до стока внутри вложенного цикла for с
// фиксированным количеством итераций.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int divident = 24, divisor = 7, result;

  int var, var2;

  scanf("%d", &divisor);

  for (var = 0; var < 13; var++) {
    for (var2 = var; var2 < 19; var2++) {
      result = divident / divisor; // FLAW
    }
  }
}
