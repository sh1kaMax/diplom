// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-basic-sub_not_zero-div_op.json
//
// Ненулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 126; }

void func(int param) {
  int divident = 34, divisor = 6, result;
  int var_a = 100;
  int var_b = 106;

  int var = 0;

  divisor = var_a - var_b;

  callee(&var);

  if (var > 95) {
    exit(0);
  }

  result = divident / divisor;
}
