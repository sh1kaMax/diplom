// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-inverted.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, выход в случае ложности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 93; }

void func(void) {
  int divident = 41, divisor = 8, result;

  divisor = wrapper(42);
  divisor -= 90;

  if (!(divisor == 0)) {
    exit(0);
  }

  result = divident / divisor;
}
