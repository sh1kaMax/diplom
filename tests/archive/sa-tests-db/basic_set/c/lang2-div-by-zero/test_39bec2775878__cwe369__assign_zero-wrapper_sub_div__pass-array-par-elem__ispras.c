// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1790 / (wrapper_par - 15); }

void func(int param) {
  int divident = 56, divisor = 4, result;

  int arr[100];
  int some_var = 34;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[65] = 7;

  if (some_var) {
    divisor = 15;
  }

  if (arr[param]) {
    result = wrapper(divisor); // FLAW
  }
}
