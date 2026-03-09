// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int divident = 23, divisor = 10, result;

  int var;

  scanf("%d", &divisor);

  var = 0;

  do {
    var++;
  } while (var < 12);

  result = divident / divisor; // FLAW
}
