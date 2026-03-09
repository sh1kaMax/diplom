// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 89; }

void func(int param) {
  int divident = 51, divisor = 10, result;

  divisor = wrapper(39);
  divisor -= 89;

  if (param > 35 && param < 70) {
    result = divident / divisor; // FLAW
  }
}
