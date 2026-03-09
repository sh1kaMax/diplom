// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: if-check-inverted.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, выход в случае ложности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1327 / (wrapper_par - 10); }

void func(void) {
  int divident = 31, divisor = 7, result;

  divisor = 10;

  if (!(divisor == 0)) {
    exit(0);
  }

  result = wrapper(divisor); // FLAW
}
