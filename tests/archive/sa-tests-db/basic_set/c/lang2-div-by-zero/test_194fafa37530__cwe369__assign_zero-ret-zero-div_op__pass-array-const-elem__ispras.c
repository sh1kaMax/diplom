// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-div_op.json
//
// Нулевое значение присваивается вызовом функции, возвращающей ноль.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 0; }

void func(int param) {
  int divident = 61, divisor = 7, result;

  int arr[100];
  arr[49] = param;
  arr[85] = 7;

  if (param) {
    divisor = wrapper(46);
  }

  param = arr[49];

  if (param) {
    result = divident / divisor; // FLAW
  }
}
