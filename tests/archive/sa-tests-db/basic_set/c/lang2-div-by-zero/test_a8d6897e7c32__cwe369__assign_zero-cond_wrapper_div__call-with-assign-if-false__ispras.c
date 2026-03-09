// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: call-with-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1492 / wrapper_par1;
}

void callee(int *pointer_param, int param1) {
  if (param1 > 0)
    *pointer_param = 388;
}

void func(int param) {
  int divident = 69, divisor = 8, result;

  int var = 0;

  divisor = 0;

  callee(&var, 2);

  if (var > 33) {
    exit(0);
  }

  result = wrapper(divisor, divident);
}
