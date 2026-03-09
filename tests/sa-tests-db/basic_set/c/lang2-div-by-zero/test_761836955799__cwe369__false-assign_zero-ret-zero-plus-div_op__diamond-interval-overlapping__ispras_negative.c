// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 8; }

void func(int param) {
  int divident = 34, divisor = 4, result;

  if (param > 10 && param < 75) {
    divisor = wrapper(27);
    divisor -= 6;
  }

  if (param > 24 && param < 69) {
    result = divident / divisor;
  }
}
