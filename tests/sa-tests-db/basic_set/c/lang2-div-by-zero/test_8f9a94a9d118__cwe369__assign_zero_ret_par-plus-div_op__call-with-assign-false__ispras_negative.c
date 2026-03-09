// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void callee(int *pointer_param) { *pointer_param = 96; }

void func(int param) {
  int divident = 30, divisor = 9, result;

  int var = 0;

  divisor = wrapper(34);
  divisor -= 34;

  callee(&var);

  if (var > 31) {
    exit(0);
  }

  result = divident / divisor;
}
