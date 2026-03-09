// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-cond_wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции только, если 2й аргумент
// больше нуля.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

int wrapper(int wrapper_par1, int wrapper_par2) {
  if (wrapper_par2 <= 0)
    return 0;
  return 1066 / wrapper_par1;
}

void callee(int *pointer_param) { *pointer_param = 166; }

void func(int param) {
  int divident = 26, divisor = 8, result;

  int var = 0;

  divisor = 0;

  callee(&var);

  if (var > 32) {
    exit(0);
  }

  result = wrapper(divisor, divident);
}
