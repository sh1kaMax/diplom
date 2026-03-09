// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(void) {
  int divident = 30, divisor = 8, result;

  divisor = wrapper(52);

  if (!(divisor == 0)) {
    divisor = 8;
  }

  result = divident / divisor; // FLAW
}
