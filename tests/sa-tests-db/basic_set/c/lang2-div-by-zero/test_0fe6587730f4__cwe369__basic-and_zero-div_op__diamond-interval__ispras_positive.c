// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-and_zero-div_op.json
//
// Нулевое значение получается как результат побитового и.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 63, divisor = 10, result;
  int var_a = 0;

  if (param > 3 && param < 11) {
    divisor = param & var_a;
  }

  if (param > 3 && param < 11) {
    result = divident / divisor; // FLAW
  }
}
