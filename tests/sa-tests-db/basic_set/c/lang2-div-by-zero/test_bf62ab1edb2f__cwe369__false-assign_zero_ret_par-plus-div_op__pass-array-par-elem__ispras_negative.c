// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero_ret_par-plus-div_op.json
//
// Ненулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(int param) {
  int divident = 21, divisor = 10, result;

  int arr[100];
  int some_var = 36;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[94] = 7;

  if (some_var) {
    divisor = wrapper(69);
    divisor -= 62;
  }

  if (arr[param]) {
    result = divident / divisor;
  }
}
