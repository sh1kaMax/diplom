// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1234 / (wrapper_par - 18); }

void callee(int *pointer_param) { *pointer_param = 214; }

void func(void) {
  int divident = 43, divisor = 7, result;

  int var = 0;

  divisor = 18;

  callee(&var);

  if (var > 983) {
    exit(0);
  }

  result = wrapper(divisor); // FLAW
}
