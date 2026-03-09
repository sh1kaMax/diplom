// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_no_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции на ненулевую константу.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par / 11; }

void callee(int *pointer_param) { *pointer_param = 92; }

void func(int param) {
  int divident = 70, divisor = 5, result;

  int var = 0;

  divisor = 0;

  callee(&var);

  if (var > 690) {
    exit(0);
  }

  result = wrapper(divisor);
}
