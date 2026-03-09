// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции. Ошибки нет.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 1;
  return 1230 / wrapper_par1;
}

void callee(int *pointer_param) { *pointer_param = 487; }

void func(void) {
  int divident = 23, divisor = 4, result;

  int var = 0;

  divisor = 0;

  callee(&var);

  if (var > 976) {
    exit(0);
  }

  result = wrapper(divisor, -divident);
}
