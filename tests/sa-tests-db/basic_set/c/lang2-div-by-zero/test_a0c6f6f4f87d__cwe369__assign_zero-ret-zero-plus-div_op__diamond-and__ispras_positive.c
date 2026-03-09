// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 97; }

void func(int param) {
  int divident = 33, divisor = 3, result;

  if (param & 0x1D) {
    divisor = wrapper(26);
    divisor -= 97;
  }

  if (param & 0x1D) {
    result = divident / divisor; // FLAW
  }
}
