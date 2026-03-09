// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_zero-div_op.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond.c
// Достижимый путь от источника до стока с проверками одного и того же простого
// условия, результат которого зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  int divident = 33, divisor = 5, result;

  if (param > 25) {
    divisor = 0;
  }

  if (param > 25) {
    result = divident / divisor; // FLAW
  }
}
