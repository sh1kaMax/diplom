// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_div.json
//
// Нулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции.
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1712 / wrapper_par; }

void func(void) {
  int divident = 48, divisor = 3, result;

  int var;

  divisor = 0;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    result = wrapper(divisor);
    break;
  }
}
