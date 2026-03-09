// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: if-else-check-filtered.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// условием которого является условие наличия уязвимости.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1045 / (wrapper_par - 10); }

void func(void) {
  int divident = 40, divisor = 9, result;

  divisor = 10;

  if (divisor == 0) {
    divisor = 9;
  } else {
    result = wrapper(divisor);
  }
}
