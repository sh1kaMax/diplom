// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: diamond-overlapping-inverted.c
// Недостижимый путь от источника до стока с проверками несовместимых простых
// условий, результат которых зависит от параметра функции.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(int param) {
  int divident = 43, divisor = 7, result;

  if (param > 50) {
    divisor = wrapper(25);
    divisor -= 25;
  }

  if (param < 30) {
    result = divident / divisor;
  }
}
