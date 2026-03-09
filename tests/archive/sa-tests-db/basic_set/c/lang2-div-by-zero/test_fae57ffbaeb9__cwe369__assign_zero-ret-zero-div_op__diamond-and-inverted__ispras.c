// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-and-inverted.c
// Недостижимый путь от источника до стока с проверками противоположных условий
// с использованием битового и. Приоритет битового и ниже, чем у сравнения,
// поэтому второе условие всегда ложное.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(int param) {
  int divident = 26, divisor = 3, result;

  if ((param & 0x10) > 0) {
    divisor = wrapper(61);
  }

  if ((param & 0x10) == 0) {
    result = divident / divisor;
  }
}
