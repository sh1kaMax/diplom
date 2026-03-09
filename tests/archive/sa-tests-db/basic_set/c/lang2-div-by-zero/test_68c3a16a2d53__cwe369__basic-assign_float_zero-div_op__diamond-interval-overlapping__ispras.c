// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

void func(int param) {
  float divident = 66.86, divisor = 40.64, result;

  if (param > 12 && param < 62) {
    divisor = 0.0;
  }

  if (param > 55 && param < 60) {
    result = divident / divisor; // FLAW
  }
}
