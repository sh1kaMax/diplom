// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1399 / wrapper_par; }

void callee(int *pointer_param) { *pointer_param = 57; }

void func(void) {
  int divident = 69, divisor = 7, result;

  int var = 0;

  divisor = 0;

  callee(&var);

  if (var > 30) {
    exit(0);
  }

  result = wrapper(divisor);
}
