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

int wrapper(int wrapper_par) { return 1260 / (wrapper_par - 10); }

void callee(int *pointer_param) { *pointer_param = 57; }

void func(int param) {
  int divident = 48, divisor = 5, result;

  int var = 0;

  divisor = 10;

  callee(&var);

  if (var > 45) {
    exit(0);
  }

  result = wrapper(divisor);
}
