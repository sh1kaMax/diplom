// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-and_zero-div_op.json
//
// Нулевое значение получается как результат побитового и.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 57, divisor = 9, result;
  int var_a = 0;

  divisor = param & var_a;

  if (param > 29 && param < 55) {
    result = divident / divisor; // FLAW
  }
}
