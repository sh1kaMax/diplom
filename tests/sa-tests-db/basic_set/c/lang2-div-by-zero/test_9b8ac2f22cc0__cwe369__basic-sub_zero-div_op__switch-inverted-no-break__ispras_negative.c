// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-sub_zero-div_op.json
//
// Нулевое значение получается как результат вычитания.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока.

#include <stdlib.h>

void func(void) {
  int divident = 59, divisor = 10, result;
  int var_a = 60;
  int var_b = 60;

  int var;

  divisor = var_a - var_b;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    result = divident / divisor;
    break;
  }
}
