// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1825 / (wrapper_par - 17); }

void func(int param) {
  int divident = 47, divisor = 5, result;

  if (param > 48 && param < 69) {
    divisor = 17;
  }

  if (param <= 48 || param >= 69) {
    result = wrapper(divisor);
  }
}
