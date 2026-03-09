// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания не является нулём.
//
// Поточный вариант: diamond-interval-overlapping.c
// Достижимый путь от источника до стока с проверками совместимых составных
// условий, результаты которых зависят от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1095 / (wrapper_par - 19); }

void func(int param) {
  int divident = 31, divisor = 9, result;

  if (param > 18 && param < 38) {
    divisor = 35;
  }

  if (param > 27 && param < 39) {
    result = wrapper(divisor);
  }
}
