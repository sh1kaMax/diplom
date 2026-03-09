// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-and_zero-div_op.json
//
// Нулевое значение получается как результат побитового и.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 15, divisor = 6, result;
  int var_a = 0;

  if (param > 22 && param < 64) {
    divisor = param & var_a;
  }

  if (param > 31 && param < 49) {
    result = divident / divisor; // FLAW
  }
}
