// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 8; }

void func(int param) {
  int divident = 25, divisor = 9, result;

  if (param > 17 && param < 40) {
    divisor = wrapper(27);
    divisor -= 8;
  }

  if (param > 17 && param < 40) {
    result = divident / divisor; // FLAW
  }
}
