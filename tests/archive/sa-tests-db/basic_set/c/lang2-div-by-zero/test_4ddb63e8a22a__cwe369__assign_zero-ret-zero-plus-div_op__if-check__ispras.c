// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, выход в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 76; }

void func(void) {
  int divident = 16, divisor = 8, result;

  divisor = wrapper(47);
  divisor -= 76;

  if (divisor == 0) {
    exit(0);
  }

  result = divident / divisor;
}
