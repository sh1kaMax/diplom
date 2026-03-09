// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 47; }

void func(int param) {
  int divident = 59, divisor = 5, result;

  int arr[100];
  arr[11] = param;
  arr[98] = 7;

  if (param) {
    divisor = wrapper(57);
    divisor -= 47;
  }

  param = arr[11];

  if (param) {
    result = divident / divisor; // FLAW
  }
}
