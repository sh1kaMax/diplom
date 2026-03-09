// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(int param) {
  int divident = 45, divisor = 6, result;

  int arr[100];
  int some_var = 13;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[74] = 7;

  if (some_var) {
    divisor = wrapper(45);
  }

  if (arr[param]) {
    result = divident / divisor; // FLAW
  }
}
