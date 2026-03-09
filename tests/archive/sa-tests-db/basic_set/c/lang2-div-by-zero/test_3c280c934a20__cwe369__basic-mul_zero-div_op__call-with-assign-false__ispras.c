// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-mul_zero-div_op.json
//
// Нулевое значение получается как результат умножения.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 172; }

void func(int param) {
  int divident = 26, divisor = 6, result;
  int var_a = 0;

  int var = 0;

  divisor = param * var_a;

  callee(&var);

  if (var > 109) {
    exit(0);
  }

  result = divident / divisor;
}
