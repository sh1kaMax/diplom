// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: ternary.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними с помощью тернарного оператора, выполнение достигает стока в
// случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 22; }

void func(void) {
  int divident = 38, divisor = 9, result;

  int var;

  divisor = wrapper(42);
  divisor -= 22;

  var = (divisor == 0 ? 1 : 0);

  if (var) {
    result = divident / divisor; // FLAW
  }
}
