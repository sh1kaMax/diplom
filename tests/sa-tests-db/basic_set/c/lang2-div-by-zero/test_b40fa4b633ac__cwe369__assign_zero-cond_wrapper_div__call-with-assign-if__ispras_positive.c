// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: call-with-assign-if.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель, если 2й параметр больше нуля. При вызове
// функции 2й параметр больше нуля, поэтому присвоение происходит. Присвоенное
// значение сравнивается с константой, проверка неуспешна и выполнение достигает
// стока.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1479 / wrapper_par1;
}

void callee(int *pointer_param, int param) {
  if (param > 0)
    *pointer_param = 238;
}

void func(void) {
  int divident = 56, divisor = 10, result;

  int var = 0;

  divisor = 0;

  callee(&var, 7);

  if (var > 943) {
    exit(0);
  }

  result = wrapper(divisor, divident); // FLAW
}
