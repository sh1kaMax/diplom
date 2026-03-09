// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 75; }

void func(int param) {
  int divident = 57, divisor = 7, result;

  if (param > 4 && param < 36) {
    divisor = wrapper(33);
    divisor -= 75;
  }

  if (param > 27 && param < 30) {
    result = divident / divisor; // FLAW
  }
}
