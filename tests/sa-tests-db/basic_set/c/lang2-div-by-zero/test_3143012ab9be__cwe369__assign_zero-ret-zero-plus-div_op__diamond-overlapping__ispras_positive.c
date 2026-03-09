// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 38; }

void func(int param) {
  int divident = 56, divisor = 10, result;

  if (param > 33) {
    divisor = wrapper(52);
    divisor -= 38;
  }

  if (param < 47) {
    result = divident / divisor; // FLAW
  }
}
