// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero_ret_par-plus-div_op.json
//
// Ненулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void callee(int *pointer_param) { *pointer_param = 234; }

void func(int param) {
  int divident = 17, divisor = 4, result;

  int var = 0;

  divisor = wrapper(38);
  divisor -= 36;

  callee(&var);

  if (var > 494) {
    exit(0);
  }

  result = divident / divisor;
}
