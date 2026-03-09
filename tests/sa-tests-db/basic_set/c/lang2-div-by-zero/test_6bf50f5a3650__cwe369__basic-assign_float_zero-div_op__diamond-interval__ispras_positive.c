// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

void func(int param) {
  float divident = 33.49, divisor = 9.57, result;

  if (param > 34 && param < 66) {
    divisor = 0.0;
  }

  if (param > 34 && param < 66) {
    result = divident / divisor; // FLAW
  }
}
