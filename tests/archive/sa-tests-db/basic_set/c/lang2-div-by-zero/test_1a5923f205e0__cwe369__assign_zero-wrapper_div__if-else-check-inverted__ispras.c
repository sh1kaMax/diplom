// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1890 / wrapper_par; }

void func(void) {
  int divident = 32, divisor = 5, result;

  divisor = 0;

  if (!(divisor == 0)) {
    exit(0);
  } else {
    result = wrapper(divisor); // FLAW
  }
}
