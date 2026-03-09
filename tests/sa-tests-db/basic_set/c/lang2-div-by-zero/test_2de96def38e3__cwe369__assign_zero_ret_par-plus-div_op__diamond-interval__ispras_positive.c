// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-interval.c
// Достижимый путь от источника до стока с проверками одного и того же
// составного условия, результат которого зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(int param) {
  int divident = 30, divisor = 6, result;

  if (param > 46 && param < 70) {
    divisor = wrapper(49);
    divisor -= 49;
  }

  if (param > 46 && param < 70) {
    result = divident / divisor; // FLAW
  }
}
