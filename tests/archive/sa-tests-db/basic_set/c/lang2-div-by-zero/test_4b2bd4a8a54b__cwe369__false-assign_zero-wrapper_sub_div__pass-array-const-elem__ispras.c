// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1107 / (wrapper_par - 17); }

void func(int param) {
  int divident = 39, divisor = 3, result;

  int arr[100];
  arr[23] = param;
  arr[59] = 7;

  if (param) {
    divisor = 28;
  }

  param = arr[23];

  if (param) {
    result = wrapper(divisor);
  }
}
