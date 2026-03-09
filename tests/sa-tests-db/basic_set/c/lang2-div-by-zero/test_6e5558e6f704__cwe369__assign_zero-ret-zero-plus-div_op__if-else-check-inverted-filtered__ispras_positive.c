// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check-inverted-filtered.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 12; }

void func(void) {
  int divident = 58, divisor = 4, result;

  divisor = wrapper(52);
  divisor -= 12;

  if (!(divisor == 0)) {
    divisor = 4;
  } else {
    result = divident / divisor; // FLAW
  }
}
