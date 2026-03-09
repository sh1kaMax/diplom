// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: false-assign_zero_ret_par-plus-div_op.json
//
// Ненулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(void) {
  int divident = 62, divisor = 5, result;

  int var;

  divisor = wrapper(39);
  divisor -= 32;

  var = 0;

  switch (var) {
  case 0:
    result = divident / divisor;
    break;
  case 1:
    exit(0);
  }
}
