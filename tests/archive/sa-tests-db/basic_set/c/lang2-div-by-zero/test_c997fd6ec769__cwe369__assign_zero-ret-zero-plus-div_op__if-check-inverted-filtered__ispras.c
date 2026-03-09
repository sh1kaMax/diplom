// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 64; }

void func(void) {
  int divident = 26, divisor = 6, result;

  divisor = wrapper(68);
  divisor -= 64;

  if (!(divisor == 0)) {
    divisor = 6;
  }

  result = divident / divisor; // FLAW
}
