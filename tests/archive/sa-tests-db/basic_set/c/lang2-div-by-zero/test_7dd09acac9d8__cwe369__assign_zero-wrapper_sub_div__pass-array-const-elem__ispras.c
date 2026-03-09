// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: pass-array-const-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1920 / (wrapper_par - 20); }

void func(int param) {
  int divident = 45, divisor = 9, result;

  int arr[100];
  arr[24] = param;
  arr[92] = 7;

  if (param) {
    divisor = 20;
  }

  param = arr[24];

  if (param) {
    result = wrapper(divisor); // FLAW
  }
}
