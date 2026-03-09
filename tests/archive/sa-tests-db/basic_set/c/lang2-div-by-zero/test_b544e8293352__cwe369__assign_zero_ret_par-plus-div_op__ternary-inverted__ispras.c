// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: ternary-inverted.c
// Недостижимый путь от источника до стока с проверкой условия наличия
// уязвимости между ними с помощью тернарного оператора, выполнение не достигает
// стока в случае истинности проверки.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(void) {
  int divident = 68, divisor = 7, result;

  int var;

  divisor = wrapper(15);
  divisor -= 15;

  var = (divisor == 0 ? 0 : 1);

  if (var) {
    result = divident / divisor;
  }
}
