// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-ret-zero-plus-div_op.json
//
// Нулевое значение присваивается комбинацией вызова функции и вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 68; }

void func(void) {
  int divident = 42, divisor = 3, result;

  int var;

  divisor = wrapper(27);
  divisor -= 68;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    result = divident / divisor;
    break;
  }
}
