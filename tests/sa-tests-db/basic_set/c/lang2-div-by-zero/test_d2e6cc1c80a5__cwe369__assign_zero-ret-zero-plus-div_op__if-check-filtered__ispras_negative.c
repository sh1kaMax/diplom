// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 12; }

void func(void) {
  int divident = 39, divisor = 8, result;

  divisor = wrapper(51);
  divisor -= 12;

  if (divisor == 0) {
    divisor = 8;
  }

  result = divident / divisor;
}
