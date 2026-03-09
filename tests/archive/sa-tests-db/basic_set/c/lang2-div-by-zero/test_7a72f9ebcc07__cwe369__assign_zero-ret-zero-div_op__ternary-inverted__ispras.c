// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(void) {
  int divident = 70, divisor = 4, result;

  int var;

  divisor = wrapper(26);

  var = (divisor == 0 ? 0 : 1);

  if (var) {
    result = divident / divisor;
  }
}
