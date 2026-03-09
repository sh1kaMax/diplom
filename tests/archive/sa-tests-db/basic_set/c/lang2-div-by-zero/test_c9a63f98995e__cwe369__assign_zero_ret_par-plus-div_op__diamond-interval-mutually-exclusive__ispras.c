// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval-mutually-exclusive.c
// Недостижимый путь от источника до стока с проверками взаимоисключающих
// составных условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(int param) {
  int divident = 20, divisor = 5, result;

  if (param > 43 && param < 55) {
    divisor = wrapper(50);
    divisor -= 50;
  }

  if (param <= 43 || param >= 55) {
    result = divident / divisor;
  }
}
