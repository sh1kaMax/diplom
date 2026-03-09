// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-tainted-div_op.json
//
// Нулевое значение получается за счёт вызова функции, получающей внешние
// данные. Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdio.h>
#include <stdlib.h>

void func(void) {
  int divident = 15, divisor = 10, result;

  int var;

  scanf("%d", &divisor);

  var = 0;

  switch (var) {
  case 0:
    result = divident / divisor; // FLAW
    break;
  case 1:
    exit(0);
  }
}
