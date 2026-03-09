// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 10; }

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 115;
}

void func(int param) {
  int divident = 24, divisor = 6, result;

  int var = 0;

  divisor = 0;

  callee(&var, 6);

  if (var > 836) {
    exit(0);
  }

  result = wrapper(divisor);
}
