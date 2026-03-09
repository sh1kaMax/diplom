// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-assign_float_zero-div_op.json
//
// Нулевое float значение присваивается явно.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 424; }

void func(int param) {
  float divident = 38.14, divisor = 46.13, result;

  int var = 0;

  divisor = 0.0;

  callee(&var);

  if (var > 304) {
    exit(0);
  }

  result = divident / divisor;
}
