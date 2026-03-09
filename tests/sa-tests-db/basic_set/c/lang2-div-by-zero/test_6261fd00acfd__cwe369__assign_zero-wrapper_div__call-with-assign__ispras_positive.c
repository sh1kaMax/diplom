// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1619 / wrapper_par; }

void callee(int *pointer_param) { *pointer_param = 119; }

void func(int param) {
  int divident = 19, divisor = 9, result;

  int var = 0;

  divisor = 0;

  callee(&var);

  if (var > 834) {
    exit(0);
  }

  result = wrapper(divisor); // FLAW
}
