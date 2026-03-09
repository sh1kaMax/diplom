// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: basic-compare_zero-div_op.json
//
// Параметр проверяется на возможное нулевое значение.
// Деление осуществляется непосредственно (с помощью операции деления).
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока

#include <stdlib.h>

int func(int param) {
  int divident = 51, result;

  int var;

  if (param == 0) {
    divident = 46;
  }

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    result = divident / param;
    break;
  }

  return result;
}
