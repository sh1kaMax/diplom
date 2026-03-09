// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 38; }

void callee(int *pointer_param) { *pointer_param = 115; }

void func(void) {
  int divident = 37, divisor = 4, result;

  int var = 0;

  divisor = wrapper(21);
  divisor -= 38;

  callee(&var);

  if (var > 65) {
    exit(0);
  }

  result = divident / divisor;
}
