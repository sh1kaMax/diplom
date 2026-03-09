// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem-false.c
// Недостижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 34; }

void func(int param) {
  int divident = 68, divisor = 4, result;

  int arr[100];
  arr[11] = !param;
  arr[79] = 7;

  if (param) {
    divisor = wrapper(29);
    divisor -= 34;
  }

  param = arr[11];

  if (param) {
    result = divident / divisor;
  }
}
