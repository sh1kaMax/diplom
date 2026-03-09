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

int wrapper(int wrapper_par) { return 10; }

void callee(int *pointer_param) { *pointer_param = 96; }

void func(int param) {
  int divident = 31, divisor = 6, result;

  int var = 0;

  divisor = wrapper(50);
  divisor -= 10;

  callee(&var);

  if (var > 49) {
    exit(0);
  }

  result = divident / divisor;
}
