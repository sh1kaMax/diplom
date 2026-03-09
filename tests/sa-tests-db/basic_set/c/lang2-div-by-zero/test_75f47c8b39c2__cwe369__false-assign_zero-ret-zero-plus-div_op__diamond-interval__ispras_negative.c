// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 30; }

void func(int param) {
  int divident = 59, divisor = 10, result;

  if (param > 35 && param < 49) {
    divisor = wrapper(25);
    divisor -= 22;
  }

  if (param > 35 && param < 49) {
    result = divident / divisor;
  }
}
