// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero_ret_par-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Вызываемая функция возвращает свой аргумент. Деление осуществляется
// непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdlib.h>

int wrapper(int wrapper_par) { return wrapper_par; }

void func(void) {
  int divident = 36, divisor = 4, result;

  int var;

  divisor = wrapper(35);
  divisor -= 35;

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    result = divident / divisor; // FLAW
    break;
  }
}
