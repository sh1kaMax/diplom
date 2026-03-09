// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond.c
// Достижимый путь от источника до стока с проверками одного и того же простого
// условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 86; }

void func(int param) {
  int divident = 29, divisor = 5, result;

  if (param > 41) {
    divisor = wrapper(44);
    divisor -= 86;
  }

  if (param > 41) {
    result = divident / divisor; // FLAW
  }
}
