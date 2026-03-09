// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(int param) {
  int divident = 70, divisor = 9, result;

  divisor = wrapper(32);
  divisor -= 32;

  if (param > 22 && param < 23) {
    result = divident / divisor;
  }
}
