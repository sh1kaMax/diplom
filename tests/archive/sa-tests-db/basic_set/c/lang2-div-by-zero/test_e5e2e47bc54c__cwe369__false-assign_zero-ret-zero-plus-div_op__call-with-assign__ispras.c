// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 79; }

void callee(int *pointer_param) { *pointer_param = 320; }

void func(int param) {
  int divident = 45, divisor = 9, result;

  int var = 0;

  divisor = wrapper(62);
  divisor -= 73;

  callee(&var);

  if (var > 990) {
    exit(0);
  }

  result = divident / divisor;
}
