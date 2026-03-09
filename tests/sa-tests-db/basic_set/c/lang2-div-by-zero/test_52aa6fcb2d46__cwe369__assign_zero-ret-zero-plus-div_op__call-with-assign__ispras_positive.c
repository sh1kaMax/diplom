// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 5; }

void callee(int *pointer_param) { *pointer_param = 225; }

void func(void) {
  int divident = 50, divisor = 10, result;

  int var = 0;

  divisor = wrapper(43);
  divisor -= 5;

  callee(&var);

  if (var > 395) {
    exit(0);
  }

  result = divident / divisor; // FLAW
}
