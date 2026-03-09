// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1320 / (wrapper_par - 10); }

void func(void) {
  int divident = 25, divisor = 9, result;

  divisor = 27;

  if (!(divisor == 0)) {
    divisor = 9;
  }

  result = wrapper(divisor);
}
