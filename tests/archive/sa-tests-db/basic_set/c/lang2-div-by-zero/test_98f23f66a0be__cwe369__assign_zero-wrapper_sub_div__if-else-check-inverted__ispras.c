// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1045 / (wrapper_par - 13); }

void func(void) {
  int divident = 21, divisor = 4, result;

  divisor = 13;

  if (!(divisor == 0)) {
    exit(0);
  } else {
    result = wrapper(divisor); // FLAW
  }
}
