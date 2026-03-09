// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(int param) {
  int divident = 51, divisor = 9, result;

  int arr[100];
  int some_var = 40;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[82] = 7;

  if (some_var) {
    divisor = wrapper(47);
    divisor -= 47;
  }

  if (arr[param]) {
    result = divident / divisor; // FLAW
  }
}
