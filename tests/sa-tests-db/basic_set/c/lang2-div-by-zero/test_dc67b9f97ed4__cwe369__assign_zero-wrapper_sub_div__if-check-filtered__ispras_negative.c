// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1471 / (wrapper_par - 20); }

void func(void) {
  int divident = 42, divisor = 3, result;

  divisor = 20;

  if (divisor == 0) {
    divisor = 3;
  }

  result = wrapper(divisor);
}
