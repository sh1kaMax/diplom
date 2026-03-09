// Авторы теста: ИСП РАН
// CWE: 369
// Название: Divide by zero
// Модельный вариант: assign_zero-wrapper_sub_div.json
//
// Ненулевое значение присваивается явно.
// Деление осуществляется внутри вызываемой функции с использованием вычитания
// константы, результат вычитания является нулём.
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока.

#include <stdlib.h>

int wrapper(int wrapper_par) { return 1574 / (wrapper_par - 20); }

void func(void) {
  int divident = 33, divisor = 5, result;

  int var;

  divisor = 20;

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    result = wrapper(divisor);
    break;
  }
}
