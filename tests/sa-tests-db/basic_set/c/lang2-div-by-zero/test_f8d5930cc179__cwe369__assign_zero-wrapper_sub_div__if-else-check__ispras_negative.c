// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: if-else-check.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// устовием которого является условие наличия уязвимости.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1299 / (wrapper_par - 15); }

void func(void) {
  int divident = 41, divisor = 9, result;

  divisor = 15;

  if (divisor == 0) {
    exit(0);
  } else {
    result = wrapper(divisor);
  }
}
