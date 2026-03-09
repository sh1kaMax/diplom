// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: if-check.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними, выход в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1993 / (wrapper_par - 18); }

void func(void) {
  int divident = 53, divisor = 9, result;

  divisor = 18;

  if (divisor == 0) {
    exit(0);
  }

  result = wrapper(divisor);
}
