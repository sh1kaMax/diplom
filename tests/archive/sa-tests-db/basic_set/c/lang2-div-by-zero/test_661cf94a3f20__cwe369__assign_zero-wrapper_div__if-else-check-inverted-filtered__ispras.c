// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: if-else-check-inverted-filtered.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1515 / wrapper_par; }

void func(void) {
  int divident = 17, divisor = 3, result;

  divisor = 0;

  if (!(divisor == 0)) {
    divisor = 3;
  } else {
    result = wrapper(divisor); // FLAW
  }
}
