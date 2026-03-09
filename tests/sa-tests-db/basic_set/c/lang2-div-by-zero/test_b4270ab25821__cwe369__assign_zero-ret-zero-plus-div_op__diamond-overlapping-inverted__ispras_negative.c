// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-overlapping-inverted.c
// Недостижимый путь от источника до стока с проверками несовместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 87; }

void func(int param) {
  int divident = 68, divisor = 10, result;

  if (param > 41) {
    divisor = wrapper(59);
    divisor -= 87;
  }

  if (param < 27) {
    result = divident / divisor;
  }
}
