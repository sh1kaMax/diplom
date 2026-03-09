// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-and_zero-div_op.json
//
// Нулевое значение получается как результат побитового и.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 116; }

void func(int param) {
  int divident = 25, divisor = 5, result;
  int var_a = 0;

  int var = 0;

  divisor = param & var_a;

  callee(&var);

  if (var > 105) {
    exit(0);
  }

  result = divident / divisor;
}
