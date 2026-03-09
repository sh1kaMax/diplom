// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: loop-for.c
// Участок кода от источника до стока с циклом for с фиксированным количеством
// итераций между ними.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int divident = 18, divisor = 9, result;

  int var;

  scanf("%d", &divisor);

  var = 0;

  for (var = 0; var < 16; var++)
    ;

  result = divident / divisor; // FLAW
}
