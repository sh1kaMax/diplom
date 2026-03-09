// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: if-else-check.c
// Недостижимый путь от источника до стока в блоке else условного оператора,
// устовием которого является условие наличия уязвимости.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 65; }

void func(void) {
  int divident = 58, divisor = 10, result;

  divisor = wrapper(30);
  divisor -= 65;

  if (divisor == 0) {
    exit(0);
  } else {
    result = divident / divisor;
  }
}
