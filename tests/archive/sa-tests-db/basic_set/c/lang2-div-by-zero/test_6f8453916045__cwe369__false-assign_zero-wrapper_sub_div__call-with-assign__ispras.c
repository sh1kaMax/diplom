// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1479 / (wrapper_par - 11); }

void callee(int *pointer_param) { *pointer_param = 92; }

void func(int param) {
  int divident = 58, divisor = 9, result;

  int var = 0;

  divisor = 28;

  callee(&var);

  if (var > 693) {
    exit(0);
  }

  result = wrapper(divisor);
}
