// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1833 / wrapper_par; }

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 233;
}

void func(void) {
  int divident = 16, divisor = 5, result;

  int var = 0;

  divisor = 0;

  callee(&var, 7);

  if (var > 758) {
    exit(0);
  }

  result = wrapper(divisor); // FLAW
}
