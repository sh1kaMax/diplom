// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1319 / (wrapper_par - 14); }

void callee(int *pointer_param) { *pointer_param = 462; }

void func(void) {
  int divident = 40, divisor = 8, result;

  int var = 0;

  divisor = 14;

  callee(&var);

  if (var > 8) {
    exit(0);
  }

  result = wrapper(divisor);
}
