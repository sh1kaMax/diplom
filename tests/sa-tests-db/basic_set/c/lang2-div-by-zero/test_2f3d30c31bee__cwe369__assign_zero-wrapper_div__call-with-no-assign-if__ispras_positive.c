// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: call-with-no-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение не происходит.
// Присвоенное значение сравнивается с константой, проверка неуспешна и
// выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1337 / wrapper_par; }

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 225;
}

void func(int param) {
  int divident = 36, divisor = 4, result;

  int var = 0;

  divisor = 0;

  callee(&var, -4);

  if (var > 373) {
    exit(0);
  }

  result = wrapper(divisor); // FLAW
}
